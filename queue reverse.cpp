void reverseq(queue **pphead, queue **pptail) {
	if(isEmpty(pphead, pptail)) {
		cout << "queue is empty" << endl;
	} else {
		queue *pptemphead = NULL, *pptemptail = NULL; // временная очередь
		int value;
		while(!isEmpty(pphead, pptail)) {
			value = dequeue(pphead, pptail); // убираем элемент из головы первоначальной очереди
			enqueueFront(&pptemphead, &pptemptail, value); // вставляем в ГОЛОВУ временной очереди полученный элемент
		}
		while(!isEmpty(pptemphead, pptemptail)) {
			value = dequeue(&pptemphead, &pptemptail); // убираем элемент из головы временной очереди
			enqueue(pphead, pptail, value); // вставляем в ХВОСТ результируещей очереди полученный элемент
		}
		deleteq(pptemp); // удаление временной очереди
	}
}

/*
0	head : 1 -> 2 -> 3

1	head : 2 -> 3
	temp : 1
	
2	head : 3
	temp : 2 -> 1
	
3	head : NULL
	temp : 3 -> 2 -> 1
	
4	head : 3
	temp : 2 -> 1
	
5	head : 3 -> 2
	temp : 1
	
6	head : 3 -> 2 -> 1
*/