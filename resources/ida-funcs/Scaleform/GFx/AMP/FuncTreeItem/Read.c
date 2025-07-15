void __thiscall Scaleform::GFx::AMP::FuncTreeItem::Read(
        Scaleform::GFx::AMP::FuncTreeItem *this,
        Scaleform::File *str,
        unsigned int version)
{
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v6; // ecx
  int (__thiscall *v7)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v8; // ecx
  int (__thiscall *v9)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v10; // ecx
  int (__thiscall *v11)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v12)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,2,Scaleform::ArrayDefaultPolicy> *p_Children; // ebp
  char *v14; // eax
  Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem> *v15; // ecx
  _DWORD *v16; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  _DWORD *p_pObject; // ebx
  unsigned int v19; // [esp+2Ch] [ebp-24h] BYREF
  Scaleform::File *v20; // [esp+30h] [ebp-20h] BYREF
  unsigned int Size; // [esp+34h] [ebp-1Ch] BYREF
  int v22; // [esp+38h] [ebp-18h] BYREF
  int v23; // [esp+3Ch] [ebp-14h]
  int v24; // [esp+40h] [ebp-10h] BYREF
  int v25; // [esp+44h] [ebp-Ch]
  int v26; // [esp+48h] [ebp-8h] BYREF
  int v27; // [esp+4Ch] [ebp-4h]
  Scaleform::File *stra; // [esp+54h] [ebp+4h]
  unsigned int strb; // [esp+54h] [ebp+4h]

  Read = str->Read;
  v22 = 0;
  v23 = 0;
  Read(str, (unsigned __int8 *)&v22, 8);
  v6 = v23;
  LODWORD(this->FunctionId) = v22;
  HIDWORD(this->FunctionId) = v6;
  v7 = str->Read;
  v24 = 0;
  v25 = 0;
  v7(str, (unsigned __int8 *)&v24, 8);
  v8 = v25;
  LODWORD(this->BeginTime) = v24;
  HIDWORD(this->BeginTime) = v8;
  v9 = str->Read;
  v26 = 0;
  v27 = 0;
  v9(str, (unsigned __int8 *)&v26, 8);
  v10 = v27;
  LODWORD(this->EndTime) = v26;
  HIDWORD(this->EndTime) = v10;
  v11 = str->Read;
  v19 = 0;
  v11(str, (unsigned __int8 *)&v19, 4);
  this->TreeItemId = v19;
  v12 = str->Read;
  v20 = 0;
  v12(str, (unsigned __int8 *)&v20, 4);
  p_Children = &this->Children;
  Size = this->Children.Data.Size;
  stra = v20;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
    &this->Children,
    (unsigned int)v20);
  if ( (unsigned int)stra > Size )
  {
    v14 = (char *)stra - Size;
    v15 = &p_Children->Data.Data[Size];
    if ( stra != (Scaleform::File *)Size )
    {
      do
      {
        if ( v15 )
          v15->pObject = 0;
        ++v15;
        --v14;
      }
      while ( v14 );
    }
  }
  for ( strb = 0; strb < this->Children.Data.Size; ++strb )
  {
    Size = 2;
    v16 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 48, &Size);
    if ( v16 )
    {
      *v16 = &Scaleform::RefCountImplCore::`vftable';
      v16[1] = 1;
      *v16 = &Scaleform::GFx::AMP::FuncTreeItem::`vftable';
      v16[9] = 0;
      v16[10] = 0;
      v16[11] = 0;
      Size = (unsigned int)v16;
    }
    else
    {
      Size = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)p_Children->Data.Data[strb].pObject;
    p_pObject = &p_Children->Data.Data[strb].pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    *p_pObject = Size;
    Scaleform::GFx::AMP::FuncTreeItem::Read(p_Children->Data.Data[strb].pObject, str, version);
  }
}
