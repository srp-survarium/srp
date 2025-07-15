Scaleform::Render::TreeText **__thiscall Scaleform::GFx::DrawTextManager::CreateText(
        Scaleform::GFx::DrawTextManager *this,
        const char *putf8Str,
        const Scaleform::Render::Rect<float> *viewRect,
        Scaleform::GFx::DrawTextManager::TextParams *ptxtParams,
        unsigned int depth)
{
  Scaleform::GFx::DrawTextImpl *v6; // eax
  Scaleform::Render::TreeText **v7; // eax
  Scaleform::Render::TreeText **v8; // esi
  Scaleform::GFx::DrawTextManager::TextParams *p_DefaultTextParams; // eax
  Scaleform::Render::Text::DocView *DocView; // eax
  Scaleform::Render::TreeRoot *pObject; // edi
  unsigned int Size; // eax
  const Scaleform::GFx::DrawTextManager::TextParams *v14; // [esp-Ch] [ebp-14h]
  Scaleform::Render::TreeNode *v15; // [esp-4h] [ebp-Ch]

  v6 = (Scaleform::GFx::DrawTextImpl *)this->pHeap->Alloc(this->pHeap, 20, 0);
  if ( v6 )
  {
    Scaleform::GFx::DrawTextImpl::DrawTextImpl(v6, (Scaleform::RefCountVImpl *)this);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  ((void (__thiscall *)(Scaleform::Render::TreeText **, const Scaleform::Render::Rect<float> *))(*v8)[2].pParent)(
    v8,
    viewRect);
  ((void (__thiscall *)(Scaleform::Render::TreeText **, const char *, int))(*v8)->pRenderer)(v8, putf8Str, -1);
  p_DefaultTextParams = ptxtParams;
  if ( !ptxtParams )
    p_DefaultTextParams = &this->pImpl->DefaultTextParams;
  v14 = p_DefaultTextParams;
  DocView = Scaleform::Render::TreeText::GetDocView(v8[3]);
  Scaleform::GFx::DrawTextManager::SetTextParams(this, DocView, v14, 0, 0);
  if ( depth == -1 )
  {
    pObject = this->pImpl->pRootNode.pObject;
    v15 = v8[3];
    Size = Scaleform::Render::TreeContainer::GetSize(pObject);
    Scaleform::Render::TreeContainer::Insert(pObject, Size, v15);
  }
  else
  {
    Scaleform::Render::TreeContainer::Insert(this->pImpl->pRootNode.pObject, depth, v8[3]);
  }
  return v8;
}


Scaleform::Render::TreeText **__thiscall Scaleform::GFx::DrawTextManager::CreateText(
        Scaleform::GFx::DrawTextManager *this,
        const wchar_t *pwstr,
        const Scaleform::Render::Rect<float> *viewRect,
        Scaleform::GFx::DrawTextManager::TextParams *ptxtParams,
        unsigned int depth)
{
  Scaleform::GFx::DrawTextImpl *v6; // eax
  Scaleform::Render::TreeText **v7; // eax
  Scaleform::Render::TreeText **v8; // esi
  Scaleform::GFx::DrawTextManager::TextParams *p_DefaultTextParams; // eax
  Scaleform::Render::Text::DocView *DocView; // eax
  Scaleform::Render::TreeRoot *pObject; // edi
  unsigned int Size; // eax
  const Scaleform::GFx::DrawTextManager::TextParams *v14; // [esp-Ch] [ebp-14h]
  Scaleform::Render::TreeNode *v15; // [esp-4h] [ebp-Ch]

  v6 = (Scaleform::GFx::DrawTextImpl *)this->pHeap->Alloc(this->pHeap, 20, 0);
  if ( v6 )
  {
    Scaleform::GFx::DrawTextImpl::DrawTextImpl(v6, (Scaleform::RefCountVImpl *)this);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  ((void (__thiscall *)(Scaleform::Render::TreeText **, const Scaleform::Render::Rect<float> *))(*v8)[2].pParent)(
    v8,
    viewRect);
  ((void (__thiscall *)(Scaleform::Render::TreeText **, const wchar_t *, int))(*v8)->pNative)(v8, pwstr, -1);
  p_DefaultTextParams = ptxtParams;
  if ( !ptxtParams )
    p_DefaultTextParams = &this->pImpl->DefaultTextParams;
  v14 = p_DefaultTextParams;
  DocView = Scaleform::Render::TreeText::GetDocView(v8[3]);
  Scaleform::GFx::DrawTextManager::SetTextParams(this, DocView, v14, 0, 0);
  if ( depth == -1 )
  {
    pObject = this->pImpl->pRootNode.pObject;
    v15 = v8[3];
    Size = Scaleform::Render::TreeContainer::GetSize(pObject);
    Scaleform::Render::TreeContainer::Insert(pObject, Size, v15);
  }
  else
  {
    Scaleform::Render::TreeContainer::Insert(this->pImpl->pRootNode.pObject, depth, v8[3]);
  }
  return v8;
}
