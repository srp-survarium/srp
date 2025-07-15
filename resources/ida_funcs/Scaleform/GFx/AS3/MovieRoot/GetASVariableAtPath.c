char __thiscall Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Value *pval,
        const char *ppathToVar)
{
  const char *v3; // edi
  Scaleform::GFx::InteractiveObject *pMainMovie; // eax
  int v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // ebp
  Scaleform::GFx::AS3::Value::V1U pLower; // eax
  unsigned int v10; // kr00_4
  Scaleform::GFx::AS3::ASVM *pObject; // ecx
  Scaleform::GFx::AS3::ASVM *v12; // ecx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *RegisteredClassTraits; // eax
  int v14; // esi
  int v15; // eax
  char v16; // bl
  int v17; // eax
  char v18; // al
  unsigned int v19; // esi
  Scaleform::GFx::ASString *v20; // eax
  Scaleform::GFx::DisplayObject *DisplayObjectByName; // esi
  Scaleform::GFx::ASStringNode *v22; // eax
  int v23; // eax
  int v24; // eax
  Scaleform::GFx::AS3::Object *v25; // eax
  const Scaleform::GFx::AS3::Value *v26; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v27; // ebx
  Scaleform::StringDataPtr *NextToken; // eax
  char *pStr; // esi
  unsigned int Size; // eax
  unsigned int v31; // edx
  unsigned int v32; // ecx
  int v33; // edx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // ecx
  Scaleform::GFx::AS3::GASRefCountBase *v35; // eax
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value::V1U v38; // esi
  int v39; // eax
  int v40; // esi
  int v41; // eax
  int v42; // ecx
  int v43; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v44; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v45; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v47; // ecx
  Scaleform::GFx::AS3::WeakProxy *v48; // eax
  Scaleform::GFx::ASStringNode *v49; // eax
  Scaleform::GFx::AS3::VM *v50; // ecx
  Scaleform::GFx::ASStringNode *v51; // eax
  Scaleform::Log *v52; // esi
  char *pData; // eax
  Scaleform::GFx::ASStringNode *v54; // eax
  Scaleform::GFx::AS3::ASVM *v55; // [esp-10h] [ebp-D8h]
  Scaleform::GFx::ASString propName; // [esp+Ch] [ebp-BCh] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [esp+13h] [ebp-B5h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+14h] [ebp-B4h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> v59; // [esp+24h] [ebp-A4h] BYREF
  Scaleform::GFx::AS3::Value::V2U v60; // [esp+28h] [ebp-A0h]
  Scaleform::GFx::AS3::Value subVal; // [esp+2Ch] [ebp-9Ch] BYREF
  Scaleform::GFx::AS3::PathTokenizer pt; // [esp+3Ch] [ebp-8Ch] BYREF
  Scaleform::GFx::AS3::Value resolvedVal; // [esp+4Ch] [ebp-7Ch] BYREF
  const char *ppath; // [esp+5Ch] [ebp-6Ch] BYREF
  Scaleform::StringBuffer *p_s; // [esp+60h] [ebp-68h]
  Scaleform::GFx::AS3::PropRef globalProp; // [esp+68h] [ebp-60h] BYREF
  Scaleform::StringBuffer s; // [esp+80h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Multiname v68; // [esp+98h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname prop; // [esp+B0h] [ebp-18h] BYREF

  v3 = ppathToVar;
  v59.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)this;
  if ( !ppathToVar )
    return 0;
  this->CheckAvm(this);
  Scaleform::GFx::AS3::Value::SetUndefined(pval);
  pMainMovie = this->pMovieImpl->pMainMovie;
  resolvedVal.Flags = 0;
  resolvedVal.Bonus.pWeakProxy = 0;
  if ( pMainMovie
    && (v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pMainMovie->AvmObjOffset)
                                        + 20))((int)pMainMovie + 4 * pMainMovie->AvmObjOffset)) != 0 )
  {
    pNode = (Scaleform::GFx::ASStringNode *)(v7 - 36);
  }
  else
  {
    pNode = 0;
  }
  pLower = (Scaleform::GFx::AS3::Value::V1U)pNode->pLower;
  propName.pNode = pNode;
  if ( !pLower.VInt )
    pLower = (Scaleform::GFx::AS3::Value::V1U)pNode->pManager;
  if ( pLower.VBool )
    --pLower.VInt;
  v.Flags = 12;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1 = pLower;
  if ( pLower.VInt )
    *(_DWORD *)(pLower.VInt + 16) = (*(_DWORD *)(pLower.VInt + 16) + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Value::Assign(&resolvedVal, &v);
  Scaleform::GFx::AS3::Value::~Value(&v);
  ppath = v3;
  v10 = strlen(v3);
  pObject = this->pAVM.pObject;
  p_s = (Scaleform::StringBuffer *)v10;
  Scaleform::GFx::AS3::Multiname::Multiname(&prop, pObject, (Scaleform::GFx::ASStringNode *)&ppath);
  v12 = this->pAVM.pObject;
  memset(&globalProp, 0, 16);
  RegisteredClassTraits = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(
                            v12,
                            &prop,
                            (Scaleform::GFx::AS3::VMAppDomain *)pNode->Size);
  Scaleform::GFx::AS3::FindGOProperty(
    &globalProp,
    this->pAVM.pObject,
    &this->pAVM.pObject->GlobalObjects,
    (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&prop,
    RegisteredClassTraits);
  if ( (globalProp.This.Flags & 0x1F) == 0
    || ((int)globalProp.pSI & 1) != 0 && ((int)globalProp.pSI & 0xFFFFFFFE) == 0
    || ((int)globalProp.pSI & 2) != 0 && ((int)globalProp.pSI & 0xFFFFFFFD) == 0 )
  {
    v14 = 0;
    v15 = *v3 - 95;
    ppath = v3;
    v16 = 1;
    if ( v15 )
    {
      v17 = v15 - 19;
      if ( v17 )
      {
        if ( v17 == 1 && !strncmp(v3 + 1, "tage", 4u) )
        {
          v14 = 5;
          v16 = 0;
        }
      }
      else if ( !strncmp(v3 + 1, "oot", 3u) )
      {
        v14 = 4;
      }
    }
    else
    {
      if ( !strncmp(v3 + 1, "root", 4u) )
      {
        v14 = 5;
      }
      else if ( !strncmp(v3 + 1, "level0", 5u) )
      {
        v14 = 7;
      }
      pNode = propName.pNode;
    }
    v18 = v3[v14];
    if ( v18 )
    {
      if ( v18 != 46 )
      {
LABEL_50:
        Scaleform::GFx::AS3::PathTokenizer::PathTokenizer(&pt, ppath);
        if ( !pt.Path.Size )
        {
LABEL_108:
          Scaleform::GFx::AS3::Value::Assign(pval, &resolvedVal);
          goto LABEL_109;
        }
        v27 = v59.pObject;
        while ( 1 )
        {
          NextToken = Scaleform::StringDataPtr::GetNextToken(&pt.Path, (Scaleform::StringDataPtr *)&ppath, 46);
          pStr = (char *)NextToken->pStr;
          pt.Token.pStr = NextToken->pStr;
          Size = NextToken->Size;
          pt.Token.Size = Size;
          v31 = Size;
          if ( pt.Path.Size < Size )
            v31 = pt.Path.Size;
          v32 = pt.Path.Size - v31;
          pt.Path.pStr += v31;
          pt.Path.Size -= v31;
          if ( *pt.Path.pStr == 46 )
          {
            v33 = v32 != 0;
            pt.Path.pStr += v33;
            pt.Path.Size = v32 - v33;
          }
          propName.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                             *(Scaleform::GFx::ASStringManager **)&v27[7].pImpl.Owner,
                             pStr,
                             Size);
          ++propName.pNode->RefCount;
          p_NullStringNode = &propName.pNode->pManager->NullStringNode;
          v.Flags = 10;
          v.Bonus.pWeakProxy = 0;
          LODWORD(v.value.VNumber) = propName;
          if ( propName.pNode == p_NullStringNode )
          {
            v.value.VS._1.VInt = 0;
            v.value.VS._2 = v60;
            v.Flags = 12;
          }
          else
          {
            ++propName.pNode->RefCount;
          }
          v35 = *(Scaleform::GFx::AS3::GASRefCountBase **)(*(_DWORD *)&v27->pImpl.Owner + 232);
          v68.Kind = MN_QName;
          v68.Obj.pObject = v35;
          if ( v35 )
            v35->RefCount = (v35->RefCount + 1) & 0x8FBFFFFF;
          v68.Name.Flags = 0;
          v68.Name.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&v68, &v);
          if ( (v.Flags & 0x1F) > 9 )
          {
            if ( (v.Flags & 0x200) != 0 )
            {
              pWeakProxy = v.Bonus.pWeakProxy;
              if ( v.Bonus.pWeakProxy->RefCount-- == 1 )
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
              memset(&v.Bonus, 0, 12);
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
            }
          }
          v38 = resolvedVal.value.VS._1;
          subVal.Flags = 0;
          subVal.Bonus.pWeakProxy = 0;
          if ( !resolvedVal.value.VS._1.VInt )
            break;
          if ( !*(_BYTE *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)resolvedVal.value.VS._1.VInt + 16))(
                            resolvedVal.value.VS._1,
                            &result,
                            &v68,
                            &subVal) )
          {
            v39 = *(_DWORD *)(v38.VInt + 20);
            if ( (unsigned int)(*(_DWORD *)(v39 + 60) - 23) < 6 && (*(_DWORD *)(v39 + 56) & 0x20) == 0 )
            {
              v40 = *(_DWORD *)(v38.VInt + 48);
              if ( ((*(_WORD *)(v40 + 62) & 0x200) != 0 ? v40 : 0) != 0
                && (v42 = *(unsigned __int8 *)((*(_WORD *)(v40 + 62) & 0x200) != 0 ? v40 + 0x41 : 65),
                    v41 = (*(_WORD *)(v40 + 62) & 0x200) != 0 ? v40 : 0,
                    (v43 = (*(int (__thiscall **)(int))(*(_DWORD *)(v41 + 4 * v42) + 20))(v41 + 4 * v42)) != 0) )
              {
                v44 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v43 - 36);
              }
              else
              {
                v44 = 0;
              }
              v45 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(v44, &v59, &propName)->pObject;
              if ( v59.pObject )
              {
                if ( ((int)v59.pObject & 1) != 0 )
                {
                  --v59.pObject;
                }
                else
                {
                  RefCount = v59.pObject->RefCount;
                  v47 = v59.pObject;
                  if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
                  {
                    v59.pObject->RefCount = RefCount - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v47);
                  }
                }
              }
              if ( !v45 )
                goto LABEL_95;
              v45->RefCount = (v45->RefCount + 1) & 0x8FBFFFFF;
              s.pData = (char *)12;
              s.Size = 0;
              s.BufferSize = (unsigned int)v45;
              Scaleform::GFx::AS3::Value::Assign(&subVal, (const Scaleform::GFx::AS3::Value *)&s);
              Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&s);
            }
          }
          Scaleform::GFx::AS3::Value::Assign(&resolvedVal, &subVal);
          if ( pt.Path.Size && (resolvedVal.Flags & 0x1F) - 12 > 3 )
          {
            v52 = Scaleform::GFx::StateBag::GetLog(
                    (Scaleform::GFx::StateBag *)&v27->pNext->8,
                    (Scaleform::Ptr<Scaleform::Log> *)&v59)->pObject;
            if ( v59.pObject )
              Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v59.pObject);
            if ( v52 )
            {
              Scaleform::StringBuffer::StringBuffer(&s, Scaleform::Memory::pGlobalHeap);
              p_s = &s;
              ppath = (const char *)1;
              Scaleform::Format<Scaleform::StringDataPtr,char const *>(
                (const Scaleform::MsgFormat::Sink *)&ppath,
                "Token '{0}' in path '{1}' was not resolved to a valid Object! This may be caused by a property that is n"
                "ot of Object type, or by using reserved words/properties for MovieClip names in the display tree.",
                &pt.Token,
                &ppathToVar);
              pData = s.pData;
              if ( !s.pData )
                pData = (char *)&buf;
              Scaleform::Log::LogError(v52, pData);
              Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&s);
            }
            Scaleform::GFx::AS3::Value::SetNull(&resolvedVal);
            Scaleform::GFx::AS3::Value::~Value(&subVal);
            Scaleform::GFx::AS3::Multiname::~Multiname(&v68);
            v54 = propName.pNode;
            --propName.pNode->RefCount;
            if ( !v54->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v54);
            goto LABEL_108;
          }
          if ( (subVal.Flags & 0x1F) > 9 )
          {
            if ( (subVal.Flags & 0x200) != 0 )
            {
              v48 = subVal.Bonus.pWeakProxy;
              --subVal.Bonus.pWeakProxy->RefCount;
              if ( !v48->RefCount )
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v48);
              subVal.Flags &= 0xFFFFFDE0;
              memset(&subVal.Bonus, 0, 12);
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&subVal);
            }
          }
          Scaleform::GFx::AS3::Multiname::~Multiname(&v68);
          v49 = propName.pNode;
          --propName.pNode->RefCount;
          if ( !v49->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v49);
          if ( !pt.Path.Size )
            goto LABEL_108;
        }
        Scaleform::GFx::AS3::Value::SetUndefined(pval);
LABEL_95:
        v50 = *(Scaleform::GFx::AS3::VM **)&v27->pImpl.Owner;
        if ( v50->HandleException )
          Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v50);
        Scaleform::GFx::AS3::Value::~Value(&subVal);
        Scaleform::GFx::AS3::Multiname::~Multiname(&v68);
        v51 = propName.pNode;
        --propName.pNode->RefCount;
        if ( !v51->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v51);
LABEL_99:
        Scaleform::GFx::AS3::PropRef::~PropRef(&globalProp);
        Scaleform::GFx::AS3::Multiname::~Multiname(&prop);
        Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
        return 0;
      }
      ++v14;
    }
    ppath = &v3[v14];
    if ( v16 )
    {
      v19 = pNode->RefCount;
      v20 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *)&v59.pObject[3].RefCount,
              &propName,
              "root1");
      DisplayObjectByName = Scaleform::GFx::DisplayList::GetDisplayObjectByName(
                              (Scaleform::GFx::DisplayList *)(v19 + 124),
                              v20,
                              1);
      v22 = propName.pNode;
      --propName.pNode->RefCount;
      if ( !v22->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      if ( !DisplayObjectByName || (DisplayObjectByName->Scaleform::GFx::DisplayObjectBase::Flags & 0x200) == 0 )
        goto LABEL_99;
      v23 = (*(int (__thiscall **)(int))(*((_DWORD *)&DisplayObjectByName->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + DisplayObjectByName->AvmObjOffset)
                                       + 20))((int)DisplayObjectByName + 4 * DisplayObjectByName->AvmObjOffset);
      if ( v23 )
        v24 = v23 - 36;
      else
        v24 = 0;
      if ( *(_DWORD *)(v24 + 8) )
        v25 = *(Scaleform::GFx::AS3::Object **)(v24 + 8);
      else
        v25 = *(Scaleform::GFx::AS3::Object **)(v24 + 4);
      if ( ((unsigned __int8)v25 & 1) != 0 )
        v25 = (Scaleform::GFx::AS3::Object *)((char *)v25 - 1);
      Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&s, v25);
      Scaleform::GFx::AS3::Value::Assign(&resolvedVal, v26);
      Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&s);
    }
    goto LABEL_50;
  }
  v55 = this->pAVM.pObject;
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0;
  if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&globalProp, &result, v55, &v, valGet)->Result )
  {
    Scaleform::GFx::AS3::Value::~Value(&v);
    goto LABEL_99;
  }
  Scaleform::GFx::AS3::Value::Swap(pval, &v);
  Scaleform::GFx::AS3::Value::~Value(&v);
LABEL_109:
  Scaleform::GFx::AS3::PropRef::~PropRef(&globalProp);
  Scaleform::GFx::AS3::Multiname::~Multiname(&prop);
  Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
  return 1;
}
