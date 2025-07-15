char __cdecl Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        const Scaleform::GFx::ASString *eventName,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *pcallback)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::ArrayObject *v8; // edi
  bool v9; // cc
  Scaleform::GFx::AS2::ArrayObject *v10; // eax
  Scaleform::GFx::AS2::ArrayObject *v11; // eax
  Scaleform::GFx::AS2::ArrayObject *v12; // ebp
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value *v14; // esi
  Scaleform::GFx::AS2::ObjectInterface *v15; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // ebp
  Scaleform::GFx::InteractiveObject *v17; // eax
  Scaleform::RefCountNTSImpl *v18; // esi
  Scaleform::GFx::AS2::Object *v19; // eax
  bool (__thiscall *GetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *); // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  unsigned int RefCount; // edx
  unsigned int v23; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  Scaleform::GFx::AS2::ArrayObject *v28; // [esp+2Ch] [ebp-3Ch]
  unsigned int v29; // [esp+30h] [ebp-38h]
  unsigned int Size; // [esp+38h] [ebp-30h]
  Scaleform::GFx::AS2::FunctionRef result; // [esp+3Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value v32; // [esp+48h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v33; // [esp+58h] [ebp-10h] BYREF
  Scaleform::GFx::AS2::ArrayObject *v34; // [esp+70h] [ebp+8h]

  if ( !pthis )
    return 0;
  pContext = penv->StringContext.pContext;
  p_StringContext = &penv->StringContext;
  v33.T.Type = 0;
  if ( pthis->GetMemberRaw(
         pthis,
         &penv->StringContext,
         (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[24].pMovieImpl,
         &v33) )
  {
    v7 = Scaleform::GFx::AS2::Value::ToObject(&v33, penv);
    v8 = (Scaleform::GFx::AS2::ArrayObject *)v7;
    v28 = (Scaleform::GFx::AS2::ArrayObject *)v7;
    if ( v7 )
    {
      if ( v7->GetObjectType(&v7->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
      {
        v9 = (signed int)v8->Elements.Data.Size <= 0;
        v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
        if ( !v9 )
        {
          v10 = (Scaleform::GFx::AS2::ArrayObject *)p_StringContext->pContext->pHeap->Alloc(
                                                      p_StringContext->pContext->pHeap,
                                                      80u,
                                                      0);
          if ( v10 )
          {
            Scaleform::GFx::AS2::ArrayObject::ArrayObject(v10, penv);
            v12 = v11;
            v34 = v11;
          }
          else
          {
            v34 = 0;
            v12 = 0;
          }
          Scaleform::GFx::AS2::ArrayObject::MakeDeepCopyFrom(v12, p_StringContext->pContext->pHeap, v8);
          v13 = 0;
          v29 = 0;
          Size = v12->Elements.Data.Size;
          if ( Size )
          {
            do
            {
              v14 = v12->Elements.Data.Data[v13];
              if ( v14 )
              {
                v15 = Scaleform::GFx::AS2::Value::ToObjectInterface(v14, penv);
                if ( v15 )
                {
                  v16 = 0;
                  if ( v14->T.Type == 7 )
                  {
                    v17 = Scaleform::GFx::AS2::Value::ToCharacter(v14, penv);
                    if ( v17 )
                      ++v17->RefCount;
                    v18 = v17;
                  }
                  else
                  {
                    v19 = Scaleform::GFx::AS2::Value::ToObject(v14, penv);
                    if ( v19 )
                      v19->RefCount = (v19->RefCount + 1) & 0x8FFFFFFF;
                    v18 = 0;
                    v16 = v19;
                  }
                  GetMemberRaw = v15->GetMemberRaw;
                  v32.T.Type = 0;
                  if ( GetMemberRaw(v15, &penv->StringContext, eventName, &v32) )
                  {
                    Scaleform::GFx::AS2::Value::ToFunction(&v32, &result, penv);
                    Function = result.Function;
                    if ( result.Function )
                    {
                      pcallback->Invoke(pcallback, penv, v15, &result);
                      Function = result.Function;
                    }
                    if ( (result.Flags & 2) == 0 )
                    {
                      if ( Function )
                      {
                        RefCount = Function->RefCount;
                        if ( (RefCount & 0x3FFFFFF) != 0 )
                        {
                          Function->RefCount = RefCount - 1;
                          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
                        }
                      }
                    }
                    result.Function = 0;
                    if ( (result.Flags & 1) == 0 )
                    {
                      if ( result.pLocalFrame )
                      {
                        v23 = result.pLocalFrame->RefCount;
                        pLocalFrame = result.pLocalFrame;
                        if ( (v23 & 0x3FFFFFF) != 0 )
                        {
                          result.pLocalFrame->RefCount = v23 - 1;
                          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
                        }
                      }
                    }
                    result.pLocalFrame = 0;
                  }
                  if ( v32.T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(&v32);
                  if ( v18 )
                    Scaleform::RefCountNTSImpl::Release(v18);
                  if ( v16 )
                  {
                    v25 = v16->RefCount;
                    if ( (v25 & 0x3FFFFFF) != 0 )
                    {
                      v16->RefCount = v25 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
                    }
                  }
                  v12 = v34;
                }
                v8 = v28;
              }
              v13 = v29 + 1;
              v29 = v13;
            }
            while ( v13 < Size );
          }
          v26 = v12->RefCount;
          if ( (v26 & 0x3FFFFFF) != 0 )
          {
            v12->RefCount = v26 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
          }
        }
        v27 = v8->RefCount;
        if ( (v27 & 0x3FFFFFF) != 0 )
        {
          v8->RefCount = v27 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
        }
      }
    }
  }
  if ( v33.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v33);
  return 1;
}
