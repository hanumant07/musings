#ifndef __QUEUE_H__
#define __QUEUE_H__

struct qItem {
	void *data;
	struct qItem *next;
};

struct queue {
	struct qItem head;
	struct qItem *last;
	void *(*peek)(struct queue *q);
	int (*push)(struct queue *q, void *data);
	void *(*pop)(struct queue *q);
	bool (*isEmpty)(struct queue *q);
};

struct queue *createQueue(void);
void destroyQueue(struct queue *q);

#endif
