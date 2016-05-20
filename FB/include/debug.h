#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>

#define INFO	1
#define ERR	2
#define STD_OUT	stdout
#define STD_ERR	stderr

#define LOG_MSG(lvl, stream, msg, ...)					\
			do  {						\
				char *str;				\
	                        if (lvl == INFO)			\
	                            str = "INFO";			\
	                        else if (lvl == ERR)			\
	                            str = "ERROR";			\
	                        fprintf(stream,				\
					"[%s] : %s : %d : "msg" \n",	\
					str, __FILE__, __LINE__,	\
					##__VA_ARGS__);			\
	                    } while (0)

#endif
