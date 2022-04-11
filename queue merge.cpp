void mergeq(queue **pphead1, queue **pptail1, queue **pphead2, queue **pptail2) { 
// слияние очередей - значения очереди 2 записываются в конец очереди 1
	queue *pcurrent = *pphead2;
	while(pcurrent != NULL) { // проходимся по узлам очереди 2
		enqueue(pphead1, pptail1, pcurrent->value);
		pcurrent = pcurrent->nextEl;
	}
}