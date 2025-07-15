Scaleform::RefCountVImpl **__userpurge Scaleform::GFx::TextField::CreateEditorKit@<eax>(
        Scaleform::GFx::TextField *this@<ecx>,
        int a2@<ebx>,
        int result)
{
  Scaleform::Render::Text::DocView *pObject; // eax
  Scaleform::RefCountVImpl_vtbl *v5; // edi
  Scaleform::RefCountVImpl **v6; // ebp
  Scaleform::GFx::Text::EditorKit *v7; // eax
  int v8; // eax
  int v9; // edi
  char v10; // cl
  int v11; // eax
  Scaleform::GFx::Resource *v12; // eax
  Scaleform::RefCountVImpl *v13; // edi
  Scaleform::RefCountVImpl *v14; // ebx
  Scaleform::RefCountVImpl *RefCount; // ecx
  Scaleform::GFx::StateBag *v16; // ecx
  int v17; // eax
  Scaleform::GFx::Resource *v18; // eax
  Scaleform::RefCountVImpl *v19; // edi
  Scaleform::RefCountVImpl *v20; // ecx
  Scaleform::RefCountVImpl *v21; // eax

  pObject = this->pDocument.pObject;
  v5 = (Scaleform::RefCountVImpl_vtbl *)pObject->pEditorKit.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject->pEditorKit.pObject);
  v6 = (Scaleform::RefCountVImpl **)result;
  *(_DWORD *)result = v5;
  if ( v5 )
    return v6;
  result = 78;
  v7 = (Scaleform::GFx::Text::EditorKit *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            this,
                                            144,
                                            &result);
  if ( v7 )
  {
    Scaleform::GFx::Text::EditorKit::EditorKit(v7, (Scaleform::GFx::Resource *)this->pDocument.pObject);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  if ( *v6 )
    Scaleform::RefCountImpl::Release(*v6);
  v10 = LOBYTE(this->pDef.pObject->Flags) >> 3;
  *v6 = (Scaleform::RefCountVImpl *)v9;
  if ( (v10 & 1) != 0 )
    *(_WORD *)(v9 + 128) |= 1u;
  if ( (this->pDef.pObject->Flags & 0x20) != 0 )
    *(_WORD *)(v9 + 128) |= 2u;
  v11 = ((int (__thiscall *)(Scaleform::GFx::StateBag *, int))this->pASRoot->pMovieImpl->GetStateBagImpl)(
          &this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
          a2);
  v12 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v11 + 12))(v11, 22);
  v13 = *v6;
  v14 = (Scaleform::RefCountVImpl *)v12;
  if ( v12 )
    Scaleform::RefCountImpl::AddRef(v12);
  RefCount = (Scaleform::RefCountVImpl *)v13[1].RefCount;
  if ( RefCount )
    Scaleform::RefCountImpl::Release(RefCount);
  v13[1].RefCount = (volatile int)v14;
  v16 = &this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag;
  v17 = v16->GetStateBagImpl(v16);
  v18 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v17 + 12))(v17, 23);
  v19 = (Scaleform::RefCountVImpl *)v18;
  result = (int)*v6;
  if ( v18 )
    Scaleform::RefCountImpl::AddRef(v18);
  v20 = *(Scaleform::RefCountVImpl **)(result + 16);
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  *(_DWORD *)(result + 16) = v19;
  v21 = *v6;
  if ( (this->Flags & 0x100) != 0 )
    LOWORD(v21[16].__vftable) |= 4u;
  else
    LOWORD(v21[16].__vftable) &= ~4u;
  if ( v19 )
    Scaleform::RefCountImpl::Release(v19);
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  return v6;
}
