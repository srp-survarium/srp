char __userpurge Scaleform::GFx::AS3::MovieRoot::SetVariableArray@<al>(
        Scaleform::GFx::AS3::MovieRoot *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::Movie::SetArrayType type,
        const char *ppathToVar,
        unsigned int index,
        Scaleform::GFx::ASStringNode *pdata,
        unsigned int count,
        Scaleform::GFx::Movie::SetVarType setType)
{
  unsigned int v8; // esi
  Scaleform::GFx::AS3::Value::V1U v10; // eax
  int v11; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // eax
  int v13; // ebx
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // edi
  Scaleform::GFx::AS3::Value::V1U v15; // edx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS3::Value *v17; // eax
  bool v18; // zf
  Scaleform::GFx::ASStringNode *v19; // esi
  Scaleform::GFx::AS3::Value *v20; // eax
  Scaleform::GFx::AS3::WeakProxy *v21; // eax
  void *v22; // eax
  void *pWeakProxy; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *i; // [esp+10h] [ebp-98h]
  unsigned int ia; // [esp+10h] [ebp-98h]
  unsigned int ib; // [esp+10h] [ebp-98h]
  bool found; // [esp+17h] [ebp-91h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> parray; // [esp+18h] [ebp-90h]
  unsigned int _CurrentState; // [esp+20h] [ebp-88h] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+24h] [ebp-84h] BYREF
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+34h] [ebp-74h] BYREF
  Scaleform::GFx::AS3::Value retVal; // [esp+38h] [ebp-70h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> result; // [esp+48h] [ebp-60h] BYREF
  unsigned int v37; // [esp+4Ch] [ebp-5Ch]
  Scaleform::GFx::Value gfxval; // [esp+50h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Value asVal; // [esp+68h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v40; // [esp+78h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+88h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v42; // [esp+98h] [ebp-10h] BYREF

  v8 = 0;
  _controlfp_s(a2, &dpg.fpc, 0, 0);
  _controlfp_s(a2, &_CurrentState, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  parray.pObject = 0;
  retVal.Flags = 0;
  retVal.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &retVal, ppathToVar) )
  {
    if ( (retVal.Flags & 0x1F) - 12 <= 3 )
    {
      v10 = retVal.value.VS._1;
      if ( retVal.value.VS._1.VInt )
      {
        v11 = *(_DWORD *)(retVal.value.VS._1.VInt + 20);
        if ( *(_DWORD *)(v11 + 60) == 7 && (*(_DWORD *)(v11 + 56) & 0x20) == 0 )
        {
          *(_DWORD *)(retVal.value.VS._1.VInt + 16) = (*(_DWORD *)(retVal.value.VS._1.VInt + 16) + 1) & 0x8FBFFFFF;
          parray.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)v10.VInt;
        }
      }
    }
  }
  found = 1;
  if ( !parray.pObject )
  {
    pV = Scaleform::GFx::AS3::VM::MakeArray(this->pAVM.pObject, &result)->pV;
    if ( pV )
      parray.pObject = pV;
    found = 0;
  }
  v13 = count;
  p_SA = &parray.pObject->SA;
  if ( count + index > parray.pObject->SA.Length )
    Scaleform::GFx::AS3::Impl::SparseArray::Resize(&parray.pObject->SA, count + index);
  switch ( type )
  {
    case SA_Int:
      if ( count )
      {
        do
        {
          v15 = (Scaleform::GFx::AS3::Value::V1U)*(&pdata->pData + v8);
          val.Flags = 2;
          val.Bonus.pWeakProxy = 0;
          val.value.VS._1 = v15;
          Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, v8 + index, &val);
          Scaleform::GFx::AS3::Value::~Value(&val);
          ++v8;
        }
        while ( v8 < count );
      }
      break;
    case SA_Double:
      if ( count )
      {
        do
        {
          v40.value.VNumber = *((double *)&pdata->pData + v8);
          v40.Flags = 4;
          v40.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, v8 + index, &v40);
          Scaleform::GFx::AS3::Value::~Value(&v40);
          ++v8;
        }
        while ( v8 < count );
      }
      break;
    case SA_Float:
      if ( count )
      {
        do
        {
          v.value.VNumber = *((float *)&pdata->pData + v8);
          v.Flags = 4;
          v.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, v8 + index, &v);
          Scaleform::GFx::AS3::Value::~Value(&v);
          ++v8;
        }
        while ( v8 < count );
      }
      break;
    case SA_String:
      for ( ia = 0; ia < count; ++ia )
      {
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       this->BuiltinsMgr.pStringManager,
                       *((__m128i **)&pdata->pData + ia));
        ++StringNode->RefCount;
        _CurrentState = (unsigned int)StringNode;
        Scaleform::GFx::AS3::Value::Value(&v42, (const Scaleform::GFx::ASString *)&_CurrentState);
        Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, index + ia, v17);
        Scaleform::GFx::AS3::Value::~Value(&v42);
        v18 = StringNode->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
      }
      break;
    case SA_StringW:
      for ( ib = 0; ib < count; ++ib )
      {
        v19 = Scaleform::GFx::ASStringManager::CreateStringNode(
                this->BuiltinsMgr.pStringManager,
                *((wchar_t **)&pdata->pData + ib),
                -1);
        ++v19->RefCount;
        _CurrentState = (unsigned int)v19;
        Scaleform::GFx::AS3::Value::Value(
          (Scaleform::GFx::AS3::Value *)&gfxval,
          (const Scaleform::GFx::ASString *)&_CurrentState);
        Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, index + ib, v20);
        Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&gfxval);
        v18 = v19->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      }
      break;
    case SA_Value:
      if ( count )
      {
        i = pdata;
        do
        {
          asVal.Flags = 0;
          asVal.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, i, &asVal);
          Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, v8 + index, &asVal);
          Scaleform::GFx::AS3::Value::~Value(&asVal);
          ++i;
          ++v8;
        }
        while ( v8 < count );
      }
      break;
    default:
      break;
  }
  if ( found )
  {
    if ( (retVal.Flags & 0x1F) > 9 )
    {
      if ( (retVal.Flags & 0x200) != 0 )
      {
        pWeakProxy = retVal.Bonus.pWeakProxy;
        v18 = retVal.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v18 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&retVal);
      }
    }
    if ( ((int)parray.pObject & 1) == 0 )
    {
      RefCount = parray.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        parray.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(parray.pObject);
      }
    }
    _controlfp_s(count, (unsigned int *)&result, dpg.fpc, (unsigned int)&loc_30000);
    return 1;
  }
  else
  {
    *(_QWORD *)&val.value.VNumber = __PAIR64__(v37, (unsigned int)parray.pObject);
    val.Bonus.pWeakProxy = 0;
    val.Flags = 12;
    gfxval.pObjectInterface = 0;
    gfxval.Type = VT_Undefined;
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &val, (Scaleform::GFx::ASStringNode *)&gfxval);
    LOBYTE(v13) = this->SetVariable(this, ppathToVar, &gfxval, setType);
    if ( (gfxval.Type & 0x40) != 0 )
    {
      gfxval.pObjectInterface->ObjectRelease(gfxval.pObjectInterface, &gfxval, (void *)gfxval.mValue.IValue);
      gfxval.pObjectInterface = 0;
    }
    gfxval.Type = VT_Undefined;
    if ( (val.Flags & 0x1F) > 9 )
    {
      if ( (val.Flags & 0x200) != 0 )
      {
        v21 = val.Bonus.pWeakProxy;
        --val.Bonus.pWeakProxy->RefCount;
        if ( !v21->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
        val.Flags &= 0xFFFFFDE0;
        memset(&val.Bonus, 0, 12);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
      }
    }
    if ( (retVal.Flags & 0x1F) > 9 )
    {
      if ( (retVal.Flags & 0x200) != 0 )
      {
        v22 = retVal.Bonus.pWeakProxy;
        v18 = retVal.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v18 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&retVal);
      }
    }
    _controlfp_s(v13, (unsigned int *)&result, dpg.fpc, (unsigned int)&loc_30000);
    return v13;
  }
}
