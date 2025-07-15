void __usercall btConvexHullInternal::removeEdgePair(
        btConvexHullInternal *this@<edx>,
        btConvexHullInternal::Edge *edge@<eax>)
{
  btConvexHullInternal::Edge *reverse; // ecx
  btConvexHullInternal::Edge *next; // esi
  btConvexHullInternal::Edge *v4; // esi

  reverse = edge->reverse;
  next = edge->next;
  if ( edge->next == edge )
  {
    reverse->target->edges = 0;
  }
  else
  {
    next->prev = edge->prev;
    edge->prev->next = next;
    reverse->target->edges = next;
  }
  v4 = reverse->next;
  if ( reverse->next == reverse )
  {
    edge->target->edges = 0;
  }
  else
  {
    v4->prev = reverse->prev;
    reverse->prev->next = v4;
    edge->target->edges = v4;
  }
  edge->next = 0;
  edge->prev = 0;
  edge->reverse = 0;
  edge->target = 0;
  edge->face = 0;
  edge->next = this->edgePool.freeObjects;
  this->edgePool.freeObjects = edge;
  reverse->next = 0;
  reverse->prev = 0;
  reverse->reverse = 0;
  reverse->target = 0;
  reverse->face = 0;
  reverse->next = this->edgePool.freeObjects;
  this->edgePool.freeObjects = reverse;
  --this->usedEdgePairs;
}
