Scaleform::Render::TreeText **__userpurge Scaleform::GFx::DrawTextManager::CreateText@<eax>(
        Scaleform::GFx::DrawTextManager *this@<ecx>,
        int a2@<ebx>,
        const char *putf8Str,
        const Scaleform::Render::Rect<float> *viewRect,
        Scaleform::GFx::DrawTextManager::TextParams *ptxtParams,
        unsigned int depth)
{
  Scaleform::GFx::DrawTextImpl *v7; // eax
  Scaleform::Render::TreeText **v8; // eax
  Scaleform::Render::TreeText **v9; // esi
  Scaleform::GFx::DrawTextManager::TextParams *p_DefaultTextParams; // eax
  Scaleform::Render::Text::DocView *DocView; // eax
  Scaleform::Render::TreeRoot *pObject; // edi
  unsigned int Size; // eax
  const Scaleform::GFx::DrawTextManager::TextParams *v15; // [esp-Ch] [ebp-14h]
  Scaleform::Render::TreeNodeArray *v16; // [esp-4h] [ebp-Ch]

  v7 = (Scaleform::GFx::DrawTextImpl *)this->pHeap->Alloc(this->pHeap, 20, 0);
  if ( v7 )
  {
    Scaleform::GFx::DrawTextImpl::DrawTextImpl(v7, a2, this);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  ((void (__thiscall *)(Scaleform::Render::TreeText **, const Scaleform::Render::Rect<float> *))(*v9)[2].pParent)(
    v9,
    viewRect);
  ((void (__thiscall *)(Scaleform::Render::TreeText **, const char *, int))(*v9)->pRenderer)(v9, putf8Str, -1);
  p_DefaultTextParams = ptxtParams;
  if ( !ptxtParams )
    p_DefaultTextParams = &this->pImpl->DefaultTextParams;
  v15 = p_DefaultTextParams;
  DocView = Scaleform::Render::TreeText::GetDocView(v9[3]);
  Scaleform::GFx::DrawTextManager::SetTextParams(this, DocView, v15, 0, 0);
  if ( depth == -1 )
  {
    pObject = this->pImpl->pRootNode.pObject;
    v16 = (Scaleform::Render::TreeNodeArray *)v9[3];
    Size = Scaleform::Render::TreeContainer::GetSize(pObject);
    Scaleform::Render::TreeContainer::Insert(pObject, Size, v16);
  }
  else
  {
    Scaleform::Render::TreeContainer::Insert(
      this->pImpl->pRootNode.pObject,
      depth,
      (Scaleform::Render::TreeNodeArray *)v9[3]);
  }
  return v9;
}
