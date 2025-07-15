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
  Scaleform::GFx::AS2::Object *pobj; // [esp+2Ch] [ebp-3Ch]
  unsigned int i; // [esp+30h] [ebp-38h]
  unsigned int n; // [esp+38h] [ebp-30h]
  Scaleform::GFx::AS2::FunctionRef method; // [esp+3Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value methodVal; // [esp+48h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value listenersVal; // [esp+58h] [ebp-10h] BYREF
  Scaleform::GFx::AS2::ObjectInterface *pthisa; // [esp+70h] [ebp+8h]

  if ( !pthis )
    return 0;
  pContext = penv->StringContext.pContext;
  p_StringContext = &penv->StringContext;
  listenersVal.T.Type = 0;
  if ( pthis->GetMemberRaw(
         pthis,
         &penv->StringContext,
         (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[24].pMovieImpl,
         &listenersVal) )
  {
    v7 = Scaleform::GFx::AS2::Value::ToObject(&listenersVal, penv);
    v8 = (Scaleform::GFx::AS2::ArrayObject *)v7;
    pobj = v7;
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
            pthisa = (Scaleform::GFx::AS2::ObjectInterface *)v11;
          }
          else
          {
            pthisa = 0;
            v12 = 0;
          }
          Scaleform::GFx::AS2::ArrayObject::MakeDeepCopyFrom(v12, p_StringContext->pContext->pHeap, v8);
          v13 = 0;
          i = 0;
          n = v12->Elements.Data.Size;
          if ( n )
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
                  methodVal.T.Type = 0;
                  if ( GetMemberRaw(v15, &penv->StringContext, eventName, &methodVal) )
                  {
                    Scaleform::GFx::AS2::Value::ToFunction(&methodVal, &method, penv);
                    Function = method.Function;
                    if ( method.Function )
                    {
                      pcallback->Invoke(pcallback, penv, v15, &method);
                      Function = method.Function;
                    }
                    if ( (method.Flags & 2) == 0 )
                    {
                      if ( Function )
                      {
                        RefCount = Function->RefCount;
                        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
                        {
                          Function->RefCount = RefCount - 1;
                          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
                        }
                      }
                    }
                    method.Function = 0;
                    if ( (method.Flags & 1) == 0 )
                    {
                      if ( method.pLocalFrame )
                      {
                        v23 = method.pLocalFrame->RefCount;
                        pLocalFrame = method.pLocalFrame;
                        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v23) != 0 )
                        {
                          method.pLocalFrame->RefCount = v23 - 1;
                          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
                        }
                      }
                    }
                    method.pLocalFrame = 0;
                  }
                  if ( methodVal.T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(&methodVal);
                  if ( v18 )
                    Scaleform::RefCountNTSImpl::Release(v18);
                  if ( v16 )
                  {
                    v25 = v16->RefCount;
                    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v25) != 0 )
                    {
                      v16->RefCount = v25 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
                    }
                  }
                  v12 = (Scaleform::GFx::AS2::ArrayObject *)pthisa;
                }
                v8 = (Scaleform::GFx::AS2::ArrayObject *)pobj;
              }
              v13 = i + 1;
              i = v13;
            }
            while ( v13 < n );
          }
          v26 = v12->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v26) != 0 )
          {
            v12->RefCount = v26 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
          }
        }
        v27 = v8->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v27) != 0 )
        {
          v8->RefCount = v27 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
        }
      }
    }
  }
  if ( listenersVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&listenersVal);
  return 1;
}
