void __thiscall Scaleform::GFx::AS2::PointObject::SetProperties(
        Scaleform::GFx::AS2::PointObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::AS2::Value *params)
{
  bool (__thiscall *SetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // eax
  const Scaleform::GFx::AS2::Value *v4; // ebp
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::AS2::ObjectInterface *v6; // esi
  Scaleform::GFx::AS2::GlobalContext *v7; // ecx
  bool (__thiscall *v8)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  char v9; // [esp+Fh] [ebp-1h] BYREF

  SetMemberRaw = this->SetMemberRaw;
  v4 = params;
  pContext = psc->pContext;
  v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v9 = 0;
  SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[34],
    params,
    (const Scaleform::GFx::AS2::PropFlags *)&v9);
  v7 = psc->pContext;
  v8 = v6->SetMemberRaw;
  LOBYTE(params) = 0;
  v8(
    v6,
    psc,
    (const Scaleform::GFx::ASString *)&v7->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
    v4 + 1,
    (const Scaleform::GFx::AS2::PropFlags *)&params);
}


// local variable allocation has failed, the output may be wrong!
void __userpurge Scaleform::GFx::AS2::PointObject::SetProperties(
        Scaleform::GFx::AS2::PointObject *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::Render::Point<double> *pt,
        char a6)
{
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v6; // eax
  const Scaleform::Render::Point<double> *v7; // ebp
  Scaleform::GFx::AS2::ObjectInterface *v8; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v11; // eax
  Scaleform::GFx::AS2::GlobalContext *v12; // ecx
  char v15; // [esp+20h] [ebp-10h] BYREF
  long double x; // [esp+24h] [ebp-Ch] BYREF
  int v17; // [esp+2Ch] [ebp-4h] OVERLAPPED

  v6 = this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable;
  v7 = pt;
  x = pt->x;
  v8 = &this->Scaleform::GFx::AS2::ObjectInterface;
  pContext = penv->StringContext.pContext;
  p_StringContext = &penv->StringContext;
  v15 = 3;
  LOBYTE(penv) = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, char *, Scaleform::GFx::AS2::Environment **, int, int))v6->SetMemberRaw)(
    v8,
    p_StringContext,
    &pContext->pMovieRoot->pASMovieRoot.pObject[34],
    &v15,
    &penv,
    a2,
    a3);
  if ( BYTE4(x) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&x + 4));
  v11 = v8->__vftable;
  *(double *)&v17 = v7->y;
  v12 = p_StringContext->pContext;
  BYTE4(x) = 3;
  a6 = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, volatile int *))v11->SetMemberRaw)(
    v8,
    p_StringContext,
    &v12->pMovieRoot->pASMovieRoot.pObject[34].RefCount);
  if ( (unsigned __int8)v15 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v15);
}
