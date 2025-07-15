void __userpurge Scaleform::GFx::AS2ValueObjectInterface::VisitMembers(
        Scaleform::GFx::AS2ValueObjectInterface *this@<ecx>,
        void *pdata,
        Scaleform::GFx::Value::ObjectInterface::ObjVisitor *visitor,
        bool isdobj,
        Scaleform::GFx::AS2::ObjectInterface *a5,
        _DWORD *a6,
        bool a7)
{
  Scaleform::AmpStats *v8; // eax
  _DWORD *v9; // esi
  int v10; // edi
  unsigned __int64 ProfileTicks; // rax
  const char *v12; // [esp+0h] [ebp-30h]
  Scaleform::AmpProfileLevel v13; // [esp+4h] [ebp-2Ch]
  Scaleform::AmpNativeFunctionId v14; // [esp+8h] [ebp-28h]
  Scaleform::GFx::Value_AS2ObjectData v15; // [esp+10h] [ebp-20h] BYREF
  void *(__thiscall **v16)(Scaleform::GFx::AS3::Impl::Value2StrCollector *__hidden, char); // [esp+1Ch] [ebp-14h]
  unsigned __int64 v17; // [esp+20h] [ebp-10h]
  _DWORD *v18; // [esp+28h] [ebp-8h]
  char v19; // [esp+2Ch] [ebp-4h] BYREF

  v8 = (Scaleform::AmpStats *)((int (__thiscall *)(Scaleform::GFx::AS2ValueObjectInterface *, const char *, _DWORD, int))this->GetAdvanceStats)(
                                this,
                                "ObjectInterface::VisitMembers",
                                0,
                                36);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer((Scaleform::AmpFunctionTimer *)&v19, v8, v12, v13, v14);
  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&v15, this, a5, a7);
  v18 = a6;
  v16 = &`Scaleform::GFx::AS2ValueObjectInterface::VisitMembers'::`2'::VisitorProxy::`vftable';
  v17 = __PAIR64__((unsigned int)v15.pEnv, (unsigned int)v15.pRoot);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *))v15.pObject->VisitMembers)(
    v15.pObject,
    &v15.pEnv->StringContext);
  v9 = v18;
  v15.pObject = (Scaleform::GFx::AS2::ObjectInterface *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( v18 )
  {
    v10 = *v18;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(v10 + 8))(v9, ProfileTicks - v17, (ProfileTicks - v17) >> 32);
  }
}
