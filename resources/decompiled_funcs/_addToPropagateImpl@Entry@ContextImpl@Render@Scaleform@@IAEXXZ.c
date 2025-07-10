void __thiscall Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(Scaleform::Render::ContextImpl::Entry *this)
{
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // edx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v2; // eax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // ecx

  p_PNode = &this->PNode;
  v2 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned int)this & 0xFFFFF000) + 0xC);
  pPrev = v2[4].pPrev;
  v2 += 4;
  p_PNode->pPrev = pPrev;
  p_PNode->pNext = v2;
  v2->pPrev->pNext = p_PNode;
  v2->pPrev = p_PNode;
}
