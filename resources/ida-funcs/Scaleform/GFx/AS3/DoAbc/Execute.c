void __thiscall Scaleform::GFx::AS3::DoAbc::Execute(Scaleform::GFx::AS3::DoAbc *this, Scaleform::RefCountVImpl *m)
{
  Scaleform::RefCountVImpl *v2; // esi
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // edi
  Scaleform::GFx::AS3::MovieRoot *AS3Root; // eax
  Scaleform::Log *v5; // ebx
  int v6; // esi
  Scaleform::Log *v7; // edi
  const char *v8; // eax
  Scaleform::GFx::AS3::AbcDataBuffer *pObject; // [esp-8h] [ebp-10h]
  Scaleform::GFx::DisplayObjContainer *v10; // [esp-4h] [ebp-Ch]

  v2 = m;
  v10 = (Scaleform::GFx::DisplayObjContainer *)m;
  v3 = (Scaleform::GFx::AS3::AvmDisplayObj *)(&m->__vftable + BYTE1(m[8].__vftable));
  pObject = this->pAbc.pObject;
  AS3Root = Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Root(v3);
  if ( !Scaleform::GFx::AS3::MovieRoot::ExecuteAbc(AS3Root, pObject, v10) )
  {
    v5 = Scaleform::GFx::StateBag::GetLog(
           &v3->pDispObj->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
           (Scaleform::Ptr<Scaleform::Log> *)&m)->pObject;
    if ( m )
      Scaleform::RefCountImpl::Release(m);
    if ( v5 )
    {
      v6 = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v2->__vftable[21].AddRef)(v2);
      v7 = Scaleform::GFx::StateBag::GetLog(
             &v3->pDispObj->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
             (Scaleform::Ptr<Scaleform::Log> *)&m)->pObject;
      v8 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 48))(v6);
      Scaleform::Log::LogError(v7, "Can't execute ABC from %s", v8);
      if ( m )
        Scaleform::RefCountImpl::Release(m);
    }
  }
}
