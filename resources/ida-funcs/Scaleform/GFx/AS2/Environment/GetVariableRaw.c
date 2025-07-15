bool __userpurge Scaleform::GFx::AS2::Environment::GetVariableRaw@<al>(
        Scaleform::GFx::AS2::Environment *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        Scaleform::GFx::AS2::Object *params,
        int a5,
        const Scaleform::GFx::ASString *i)
{
  const char ****v6; // esi
  Scaleform::GFx::AS2::Value *v9; // ecx
  const char ***v10; // eax
  int v11; // edi
  int v12; // edx
  int v13; // eax
  Scaleform::GFx::AS2::ObjectInterface *v14; // ebp
  int v15; // ecx
  int v16; // eax
  Scaleform::GFx::AS2::Value *v17; // edi
  const Scaleform::GFx::AS2::Value *Local; // eax
  bool v19; // zf
  Scaleform::GFx::InteractiveObject *v20; // eax
  Scaleform::GFx::AS2::Object *v21; // eax
  unsigned __int8 SWFVersion; // al
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  const Scaleform::GFx::ASString *v24; // edx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // ebp
  unsigned int Size; // eax
  Scaleform::GFx::AS2::LocalFrame *v27; // edi
  Scaleform::GFx::AS2::ArrayObject *v28; // eax
  Scaleform::GFx::AS2::ArrayObject *v29; // eax
  Scaleform::GFx::AS2::ArrayObject *v30; // ebx
  bool v31; // cc
  _DWORD *v32; // ecx
  int v33; // edx
  int v34; // ebx
  unsigned int v35; // eax
  _DWORD *v36; // ecx
  Scaleform::GFx::ASStringNode *pStringNode; // eax
  const Scaleform::GFx::AS2::Value *v38; // eax
  bool (__thiscall *SetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  bool (__thiscall *v41)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // eax
  Scaleform::GFx::AS2::GlobalContext *v42; // edx
  unsigned int RefCount; // eax
  unsigned __int8 v44; // al
  bool v45; // cf
  bool v46; // zf
  Scaleform::GFx::ASString *v47; // eax
  const Scaleform::GFx::ASString *v48; // edx
  Scaleform::GFx::AS2::LocalFrame *TopLocalFrame; // eax
  Scaleform::GFx::AS2::ObjectInterface *SuperThis; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v51; // edi
  Scaleform::GFx::AS2::GlobalContext *v52; // ecx
  const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v53; // edx
  Scaleform::GFx::AS2::ObjectInterface *v54; // eax
  Scaleform::GFx::AS2::Environment::GetVarParams *v55; // eax
  int v56; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v57; // ecx
  int v58; // edx
  Scaleform::GFx::ASStringNode *v59; // ecx
  unsigned int v60; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v61; // ecx
  unsigned int v62; // eax
  const Scaleform::GFx::ASString *v63; // ebp
  Scaleform::GFx::MovieImpl **p_pMovieImpl; // edi
  bool v65; // zf
  Scaleform::GFx::InteractiveObject *Target; // eax
  int v67; // eax
  Scaleform::GFx::AS2::Object *v68; // edi
  Scaleform::GFx::AS2::ArrayObject *v71; // [esp+1Ch] [ebp-3Ch]
  Scaleform::GFx::AS2::SuperObject *v72; // [esp+1Ch] [ebp-3Ch]
  Scaleform::GFx::AS2::Value v; // [esp+20h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::Value v74; // [esp+30h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams v75; // [esp+40h] [ebp-18h] BYREF

  v6 = (const char ****)params;
  if ( !params->pRCC )
    return 0;
  v9 = (Scaleform::GFx::AS2::Value *)params->Scaleform::GFx::AS2::ObjectInterface::__vftable;
  if ( v9 )
  {
    v.T.Type = 4;
    v.NV.Int32Value = 0;
    Scaleform::GFx::AS2::Value::operator=(v9, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  v10 = v6[2];
  if ( !v10 || (v11 = (int)v10[1] - 1, v11 < 0) )
  {
LABEL_17:
    if ( ((_BYTE)v6[5] & 1) == 0 )
    {
      v17 = (Scaleform::GFx::AS2::Value *)v6[1];
      Local = Scaleform::GFx::AS2::Environment::FindLocal(this, (const Scaleform::GFx::ASString *)*v6);
      v19 = Local == 0;
      if ( Local )
      {
        if ( v17 )
        {
          Scaleform::GFx::AS2::Value::operator=(v17, Local);
          return 1;
        }
        v19 = Local == 0;
      }
      if ( !v19 )
        return 1;
      SWFVersion = this->StringContext.SWFVersion;
      if ( SWFVersion >= 5u )
      {
        v45 = SWFVersion < 6u;
        v19 = SWFVersion == 6;
        pObject = this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
        v24 = (const Scaleform::GFx::ASString *)*v6;
        p_StringContext = &this->StringContext;
        LOBYTE(params) = !v45 && !v19;
        if ( Scaleform::GFx::ASString::CompareBuiltIn_CaseCheck(
               (Scaleform::GFx::ASString *)&pObject[21].AVMVersion,
               v24,
               (bool)params) )
        {
          Size = this->LocalFrames.Data.Size;
          if ( Size )
          {
            v27 = this->LocalFrames.Data.Data[Size - 1].pObject;
            if ( v27 )
            {
              v28 = (Scaleform::GFx::AS2::ArrayObject *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int))p_StringContext->pContext->pHeap->Alloc)(
                                                          p_StringContext->pContext->pHeap,
                                                          80,
                                                          0,
                                                          a3,
                                                          a2);
              if ( v28 )
              {
                Scaleform::GFx::AS2::ArrayObject::ArrayObject(v28, this);
                v30 = v29;
                v71 = v29;
              }
              else
              {
                v30 = 0;
                v71 = 0;
              }
              Scaleform::GFx::AS2::ArrayObject::Resize(v30, v27->NArgs);
              v31 = v27->NArgs <= 0;
              i = 0;
              if ( !v31 )
              {
                do
                {
                  v32 = &v27->Env->__vftable;
                  v33 = v32[1] - v32[2];
                  v34 = v32[6];
                  v35 = v27->FirstArgBottomIndex - (_DWORD)i;
                  v36 = v32 + 1;
                  v.NV.Int32Value = 0;
                  if ( v35 > 32 * (v34 - 1) + (v33 >> 4) )
                    pStringNode = v.V.pStringNode;
                  else
                    pStringNode = (Scaleform::GFx::ASStringNode *)(*(_DWORD *)(v36[4] + 4 * (v35 >> 5))
                                                                 + 16 * (v35 & 0x1F));
                  v30 = v71;
                  Scaleform::GFx::AS2::ArrayObject::SetElement(
                    v71,
                    (int)i,
                    (const Scaleform::GFx::AS2::Value *)pStringNode);
                  v31 = (int)&i->pNode + 1 < v27->NArgs;
                  i = (const Scaleform::GFx::ASString *)((char *)i + 1);
                }
                while ( v31 );
              }
              i = (const Scaleform::GFx::ASString *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject;
              Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)((char *)&v74.NV.NumberValue + 4), v30);
              Scaleform::GFx::AS2::Environment::AddLocal(*(Scaleform::GFx::AS2::Environment **)&v.T.Type, i + 109, v38);
              if ( BYTE4(v74.NV.NumberValue) >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v74.NV.NumberValue + 4));
              SetMemberRaw = v30->SetMemberRaw;
              pContext = p_StringContext->pContext;
              LOBYTE(i) = 7;
              ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *))SetMemberRaw)(
                &v30->Scaleform::GFx::AS2::ObjectInterface,
                p_StringContext,
                &pContext->pMovieRoot->pASMovieRoot.pObject[22]);
              v41 = v30->SetMemberRaw;
              v42 = p_StringContext->pContext;
              LOBYTE(params) = 7;
              v41(
                &v30->Scaleform::GFx::AS2::ObjectInterface,
                p_StringContext,
                (const Scaleform::GFx::ASString *)&v42->pMovieRoot->pASMovieRoot.pObject[22].RefCount,
                &v27->Caller,
                (const Scaleform::GFx::AS2::PropFlags *)&params);
              Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)v6[1], v30);
              RefCount = v30->RefCount;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                v30->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
                return 1;
              }
              return 1;
            }
          }
        }
        else
        {
          v44 = this->StringContext.SWFVersion;
          v45 = v44 < 6u;
          v46 = v44 == 6;
          if ( v44 >= 6u )
          {
            v47 = (Scaleform::GFx::ASString *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject;
            v48 = (const Scaleform::GFx::ASString *)*v6;
            LOBYTE(params) = !v45 && !v46;
            if ( Scaleform::GFx::ASString::CompareBuiltIn_CaseCheck(v47 + 103, v48, (bool)params) )
            {
              TopLocalFrame = Scaleform::GFx::AS2::Environment::GetTopLocalFrame(this, 0);
              if ( TopLocalFrame )
              {
                SuperThis = TopLocalFrame->SuperThis;
                if ( SuperThis )
                {
                  v51 = SuperThis->pProto.pObject;
                  if ( v51 )
                  {
                    v51->RefCount = (v51->RefCount + 1) & 0x8FFFFFFF;
                    v52 = p_StringContext->pContext;
                    v74.T.Type = 0;
                    v53 = (const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)v6[2];
                    v75.VarName = (const Scaleform::GFx::ASString *)&v52->pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl;
                    memset(&v75.ppNewTarget, 0, 12);
                    v75.pResult = &v74;
                    v75.pWithStack = v53;
                    Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw(this, (int)p_StringContext, &v75);
                    ((void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::ASStringContext *))v51[1].__vftable[4].~Scaleform::GFx::AS2::RefCountBaseGC<323>)(
                      &v51[1],
                      &v,
                      &this->StringContext);
                    v72 = (Scaleform::GFx::AS2::SuperObject *)p_StringContext->pContext->pHeap->Alloc(
                                                                p_StringContext->pContext->pHeap,
                                                                76u,
                                                                0);
                    if ( v72 )
                    {
                      params = (Scaleform::GFx::AS2::Object *)v51[1].RootIndex;
                      v54 = Scaleform::GFx::AS2::Value::ToObjectInterface(&v74, this);
                      Scaleform::GFx::AS2::SuperObject::SuperObject(
                        v72,
                        params,
                        v54,
                        (const Scaleform::GFx::AS2::FunctionRef *)&v);
                      params = (Scaleform::GFx::AS2::Object *)v55;
                    }
                    else
                    {
                      params = 0;
                    }
                    Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)v6[1], params);
                    Scaleform::GFx::AS2::Environment::SetLocal(
                      this,
                      (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[20].pASSupport,
                      (const Scaleform::GFx::AS2::Value *)v6[1]);
                    if ( (BYTE4(v.NV.NumberValue) & 2) == 0 )
                    {
                      if ( *(_DWORD *)&v.T.Type )
                      {
                        v56 = *(_DWORD *)(*(_DWORD *)&v.T.Type + 12);
                        v57 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v.T.Type;
                        if ( (v56 & 0x3FFFFFF) != 0 )
                        {
                          *(_DWORD *)(*(_DWORD *)&v.T.Type + 12) = v56 - 1;
                          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v57);
                        }
                      }
                    }
                    *(_DWORD *)&v.T.Type = 0;
                    if ( (BYTE4(v.NV.NumberValue) & 1) == 0 )
                    {
                      if ( v.NV.Int32Value )
                      {
                        v58 = *(_DWORD *)(v.NV.Int32Value + 12);
                        v59 = v.V.pStringNode;
                        if ( (v58 & 0x3FFFFFF) != 0 )
                        {
                          *(_DWORD *)(v.NV.Int32Value + 12) = v58 - 1;
                          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v59);
                        }
                      }
                    }
                    v.NV.Int32Value = 0;
                    if ( v74.T.Type >= 5u )
                      Scaleform::GFx::AS2::Value::DropRefs(&v74);
                    v60 = v51->RefCount;
                    if ( (v60 & 0x3FFFFFF) != 0 )
                    {
                      v51->RefCount = v60 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v51);
                    }
                    v61 = params;
                    if ( params )
                    {
                      v62 = params->RefCount;
                      if ( (v62 & 0x3FFFFFF) != 0 )
                      {
                        params->RefCount = v62 - 1;
                        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v61);
                        return 1;
                      }
                    }
                    return 1;
                  }
                }
              }
            }
          }
        }
      }
      v63 = (const Scaleform::GFx::ASString *)*v6;
      p_pMovieImpl = &this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl;
      if ( this->StringContext.SWFVersion <= 6u )
      {
        if ( !v63->pNode->pLower )
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v63->pNode);
        v65 = (*p_pMovieImpl)->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::__vftable == (Scaleform::GFx::StateBag_vtbl *)v63->pNode->pLower;
      }
      else
      {
        v65 = *p_pMovieImpl == (Scaleform::GFx::MovieImpl *)v63->pNode;
      }
      if ( v65 )
      {
        Scaleform::GFx::AS2::Value::SetAsCharacter((Scaleform::GFx::AS2::Value *)v6[1], this->Target);
        return 1;
      }
    }
    Target = this->Target;
    if ( Target )
    {
      v67 = (*(int (__thiscall **)(int))(*((_DWORD *)&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + Target->AvmObjOffset)
                                       + 4))((int)Target + 4 * Target->AvmObjOffset);
      if ( (*(unsigned __int8 (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, const char ***, const char ***))(*(_DWORD *)(v67 + 4) + 44))(
             v67 + 4,
             &this->StringContext,
             *v6,
             v6[1]) )
      {
        if ( v6[4] )
        {
          Scaleform::GFx::AS2::Value::Value(&v74, this->Target);
          Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)v6[4], &v74);
          goto LABEL_87;
        }
        return 1;
      }
      v68 = this->StringContext.pContext->pGlobal.pObject;
      if ( ((_BYTE)v6[5] & 2) == 0 )
      {
        if ( Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)*v6) )
        {
          if ( ****v6 == 95 )
          {
            Scaleform::GFx::AS2::Environment::CheckGlobalAndLevels(
              this,
              (Scaleform::GFx::ASMovieRootBase *)this,
              (Scaleform::GFx::Bool3W *)&params,
              (const Scaleform::GFx::AS2::Environment::GetVarParams *)v6);
            if ( (_BYTE)params )
              return (_BYTE)params == 1;
          }
        }
      }
      if ( v68
        && v68->GetMember(
             &v68->Scaleform::GFx::AS2::ObjectInterface,
             this,
             (const Scaleform::GFx::ASString *)*v6,
             (Scaleform::GFx::AS2::Value *)v6[1]) )
      {
        if ( v6[4] )
        {
          Scaleform::GFx::AS2::Value::Value(&v74, v68);
          Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)v6[4], &v74);
LABEL_87:
          if ( v74.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v74);
        }
        return 1;
      }
      if ( ((_BYTE)v6[5] & 4) == 0 )
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
          this,
          "GetVariableRaw(\"%s\") failed, returning UNDEFINED.\n",
          ***v6);
    }
    return 0;
  }
  while ( 1 )
  {
    v12 = (int)*v6[2];
    v13 = *(_DWORD *)(v12 + 8 * v11);
    if ( *(int *)(v12 + 8 * v11 + 4) >= 0 )
    {
      if ( !v13 )
        return 0;
      v15 = v13 + 4 * *(unsigned __int8 *)(v13 + 65);
      v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 4))(v15);
      if ( !v16 )
        return 0;
      v14 = (Scaleform::GFx::AS2::ObjectInterface *)(v16 + 4);
    }
    else
    {
      if ( !v13 )
        return 0;
      v14 = (Scaleform::GFx::AS2::ObjectInterface *)(v13 + 16);
    }
    if ( !v14 )
      return 0;
    if ( v14->GetMember(v14, this, (const Scaleform::GFx::ASString *)*v6, (Scaleform::GFx::AS2::Value *)v6[1]) )
      break;
    if ( --v11 < 0 )
      goto LABEL_17;
  }
  if ( !v6[4] )
    return 1;
  if ( (unsigned int)(v14->GetObjectType(v14) - 2) > 3 )
  {
    v21 = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::AS2::ObjectInterface::ToASObject(v14);
    Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)v6[4], v21);
  }
  else
  {
    v20 = (Scaleform::GFx::InteractiveObject *)Scaleform::GFx::AS2::ObjectInterface::ToCharacter(v14);
    Scaleform::GFx::AS2::Value::SetAsCharacter((Scaleform::GFx::AS2::Value *)v6[4], v20);
  }
  return 1;
}
