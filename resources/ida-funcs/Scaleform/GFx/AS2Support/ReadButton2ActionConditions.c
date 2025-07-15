void __thiscall Scaleform::GFx::AS2Support::ReadButton2ActionConditions(
        Scaleform::GFx::AS2Support *this,
        Scaleform::RefCountVImpl *p,
        Scaleform::GFx::ButtonDef *pbuttonDef,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::Stream *RefCount; // esi
  int v6; // eax
  unsigned int Pos; // eax
  unsigned __int16 v8; // cx
  int v9; // esi
  int v10; // ebp
  int v11; // ebx
  Scaleform::RefCountVImpl *v12; // eax
  Scaleform::GFx::Stream *v13; // ecx
  int TagEndPosition; // ebp
  Scaleform::GFx::SWFProcessInfo *Stream; // eax
  Scaleform::GFx::Stream *v16; // eax
  signed int v17; // esi
  Scaleform::GFx::Stream *v18; // eax
  Scaleform::RefCountVImpl_vtbl *v19; // [esp+10h] [ebp-4h]
  Scaleform::RefCountVImpl *v20; // [esp+18h] [ebp+4h]

  while ( 1 )
  {
    RefCount = (Scaleform::GFx::Stream *)p[106].RefCount;
    if ( !RefCount )
      RefCount = (Scaleform::GFx::Stream *)&p[6];
    v6 = RefCount->DataSize - RefCount->Pos;
    RefCount->UnusedBits = 0;
    if ( v6 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(RefCount, 2);
    Pos = RefCount->Pos;
    v8 = *(_WORD *)&RefCount->pBuffer[Pos];
    RefCount->Pos = Pos + 2;
    v9 = v8;
    v10 = v8 - 2;
    v11 = v10 + Scaleform::GFx::LoadProcess::Tell((Scaleform::GFx::LoadProcess *)p);
    v12 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(void (__thiscall *)(Scaleform::RefCountVImpl *), int, _DWORD))(*(_DWORD *)p[4].__vftable[2].AddRef + 40))(
                                        p[4].__vftable[2].AddRef,
                                        24,
                                        0);
    if ( v12 )
    {
      v12->__vftable = (Scaleform::RefCountVImpl_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v12->RefCount = 1;
      v12->__vftable = (Scaleform::RefCountVImpl_vtbl *)&Scaleform::GFx::AS2::ButtonAction::`vftable';
      v12[1].RefCount = 0;
      v12[2].__vftable = 0;
      v12[2].RefCount = 0;
      v20 = v12;
    }
    else
    {
      v20 = 0;
    }
    Scaleform::GFx::ButtonDef::AddButtonAction(pbuttonDef, (Scaleform::GFx::Resource *)v20);
    if ( !v9 )
    {
      v13 = (Scaleform::GFx::Stream *)p[106].RefCount;
      if ( !v13 )
        v13 = (Scaleform::GFx::Stream *)&p[6];
      TagEndPosition = Scaleform::GFx::Stream::GetTagEndPosition(v13);
      v10 = TagEndPosition - Scaleform::GFx::LoadProcess::Tell((Scaleform::GFx::LoadProcess *)p);
    }
    v19 = v20->__vftable;
    Stream = Scaleform::GFx::LoadProcess::GetStream((Scaleform::GFx::LoadProcess *)p);
    ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::SWFProcessInfo *, Scaleform::GFx::TagType, int))v19->AddRef)(
      v20,
      Stream,
      tagType,
      v10);
    if ( !v9 )
      break;
    v16 = (Scaleform::GFx::Stream *)p[106].RefCount;
    if ( !v16 )
      v16 = (Scaleform::GFx::Stream *)&p[6];
    v17 = Scaleform::GFx::Stream::GetTagEndPosition(v16);
    if ( (int)Scaleform::GFx::LoadProcess::Tell((Scaleform::GFx::LoadProcess *)p) >= v17 )
      break;
    v18 = (Scaleform::GFx::Stream *)p[106].RefCount;
    if ( !v18 )
      v18 = (Scaleform::GFx::Stream *)&p[6];
    Scaleform::GFx::Stream::SetPosition(v18, v11);
    Scaleform::RefCountImpl::Release(v20);
  }
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
}
