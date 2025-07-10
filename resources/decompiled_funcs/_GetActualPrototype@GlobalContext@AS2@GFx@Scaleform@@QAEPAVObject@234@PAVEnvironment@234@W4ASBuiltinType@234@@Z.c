Scaleform::GFx::AS2::Object *__thiscall Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ASBuiltinType type)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // edi
  Scaleform::GFx::MovieImpl *pMovieRoot; // edx
  Scaleform::GFx::AS2::Object *pObject; // ecx
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // ebp
  Scaleform::GFx::AS2::Object *v10; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // esi
  unsigned int RefCount; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  Scaleform::GFx::AS2::Value v; // [esp+Ch] [ebp-10h] BYREF

  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(this, type);
  v5 = Prototype;
  if ( Prototype )
    Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
  pMovieRoot = this->pMovieRoot;
  pObject = this->pGlobal.pObject;
  v.T.Type = 0;
  if ( pObject->GetMemberRaw(
         &pObject->Scaleform::GFx::AS2::ObjectInterface,
         &penv->StringContext,
         (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[8].RefCount + type,
         &v)
    && (v8 = Scaleform::GFx::AS2::Value::ToObject(&v, penv), (v9 = v8) != 0) )
  {
    v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
    if ( v8->GetMemberRaw(
           &v8->Scaleform::GFx::AS2::ObjectInterface,
           &penv->StringContext,
           (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
           &v) )
    {
      v10 = Scaleform::GFx::AS2::Value::ToObject(&v, penv);
      v11 = v10;
      if ( v10 )
        v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
      if ( v5 )
      {
        RefCount = v5->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v5->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
        }
      }
    }
    else
    {
      v11 = v5;
    }
    v13 = v9->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v13) != 0 )
    {
      v9->RefCount = v13 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
    }
  }
  else
  {
    v11 = v5;
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( v11 )
  {
    v14 = v11->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v14) != 0 )
    {
      v11->RefCount = v14 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
  return (Scaleform::GFx::AS2::Object *)v11;
}
