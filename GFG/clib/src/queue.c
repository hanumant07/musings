#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue.h>

/* Not Mutltithread Safe */
int queuePush(struct queue *q, void *data)
{
	struct qItem *item = malloc(sizeof(struct qItem));
	if (!item)
		return -1;
	item->data = data;
	item->next = NULL;
	if (q->isEmpty(q)) {
		q->head.next = item;
		q->last = item;
		return 0;
	}
	q->last->next = item;
	q->last = item;
	return 0;
}

void *queuePop(struct queue *q)
{
	if (q->isEmpty(q))
		return NULL;
	void *data = q->head.next->data;
	struct qItem *newStart = q->head.next->next;
	free(q->head.next);
	q->head.next = newStart;
	/* If next element is not present mark Queue as empty. */
	if (!q->peek(q))
		q->last = NULL;
	return data;
}

bool qIsEmpty(struct queue *q)
{
	return q->last == NULL ? true : false;
}

void *queuePeek(struct queue *q)
{
	if (q->head.next == NULL)
		return NULL;
	else
		return q->head.next->data;
}

struct queue* createQueue()
{
	struct queue *q = malloc(sizeof(struct queue));
	q->last = NULL;
	q->head.next = NULL;
	q->push = queuePush;
	q->pop = queuePop;
	q->isEmpty = qIsEmpty;
	q->peek = queuePeek;
	return q;
}

void destroyQueue(struct queue *q)
{
	struct qItem *iter = q->head.next;
	if (!q->isEmpty(q)) {
		while (iter != NULL) {
			struct qItem *temp = iter->next;
			free(iter);
			iter = temp;
		}
	}
	free(q);
}
