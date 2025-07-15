char __thiscall Scaleform::GFx::AS3::MovieRoot::SetVariableArray(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Movie::SetArrayType type,
        const char *ppathToVar,
        unsigned int index,
        Scaleform::GFx::ASStringNode *pdata,
        unsigned int count,
        Scaleform::GFx::Movie::SetVarType setType)
{
  unsigned int v7; // esi
  Scaleform::GFx::AS3::Value::V1U v9; // eax
  int v10; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // eax
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // edi
  Scaleform::GFx::AS3::Value::V1U v13; // edx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS3::Value *v15; // eax
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // esi
  Scaleform::GFx::AS3::Value *v18; // eax
  bool v19; // bl
  Scaleform::GFx::AS3::WeakProxy *v20; // eax
  void *v21; // eax
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
  unsigned int v36; // [esp+4Ch] [ebp-5Ch]
  Scaleform::GFx::Value gfxval; // [esp+50h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Value asVal; // [esp+68h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v39; // [esp+78h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+88h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v41; // [esp+98h] [ebp-10h] BYREF

  v7 = 0;
  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s(&_CurrentState, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  parray.pObject = 0;
  retVal.Flags = 0;
  retVal.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &retVal, ppathToVar) )
  {
    if ( (retVal.Flags & 0x1F) - 12 <= 3 )
    {
      v9 = retVal.value.VS._1;
      if ( retVal.value.VS._1.VInt )
      {
        v10 = *(_DWORD *)(retVal.value.VS._1.VInt + 20);
        if ( *(_DWORD *)(v10 + 60) == 7 && (*(_DWORD *)(v10 + 56) & 0x20) == 0 )
        {
          *(_DWORD *)(retVal.value.VS._1.VInt + 16) = (*(_DWORD *)(retVal.value.VS._1.VInt + 16) + 1) & 0x8FBFFFFF;
          parray.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)v9.VInt;
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
          v13 = (Scaleform::GFx::AS3::Value::V1U)*(&pdata->pData + v7);
          val.Flags = 2;
          val.Bonus.pWeakProxy = 0;
          val.value.VS._1 = v13;
          Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, v7 + index, &val);
          Scaleform::GFx::AS3::Value::~Value(&val);
          ++v7;
        }
        while ( v7 < count );
      }
      break;
    case SA_Double:
      if ( count )
      {
        do
        {
          v39.value.VNumber = *((double *)&pdata->pData + v7);
          v39.Flags = 4;
          v39.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, v7 + index, &v39);
          Scaleform::GFx::AS3::Value::~Value(&v39);
          ++v7;
        }
        while ( v7 < count );
      }
      break;
    case SA_Float:
      if ( count )
      {
        do
        {
          v.value.VNumber = *((float *)&pdata->pData + v7);
          v.Flags = 4;
          v.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, v7 + index, &v);
          Scaleform::GFx::AS3::Value::~Value(&v);
          ++v7;
        }
        while ( v7 < count );
      }
      break;
    case SA_String:
      for ( ia = 0; ia < count; ++ia )
      {
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       this->BuiltinsMgr.pStringManager,
                       *((char **)&pdata->pData + ia));
        ++StringNode->RefCount;
        _CurrentState = (unsigned int)StringNode;
        Scaleform::GFx::AS3::Value::Value(&v41, (const Scaleform::GFx::ASString *)&_CurrentState);
        Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, index + ia, v15);
        Scaleform::GFx::AS3::Value::~Value(&v41);
        v16 = StringNode->RefCount-- == 1;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
      }
      break;
    case SA_StringW:
      for ( ib = 0; ib < count; ++ib )
      {
        v17 = Scaleform::GFx::ASStringManager::CreateStringNode(
                this->BuiltinsMgr.pStringManager,
                *((const wchar_t **)&pdata->pData + ib),
                -1);
        ++v17->RefCount;
        _CurrentState = (unsigned int)v17;
        Scaleform::GFx::AS3::Value::Value(
          (Scaleform::GFx::AS3::Value *)&gfxval,
          (const Scaleform::GFx::ASString *)&_CurrentState);
        Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, index + ib, v18);
        Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&gfxval);
        v16 = v17->RefCount-- == 1;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
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
          Scaleform::GFx::AS3::Impl::SparseArray::Set(p_SA, v7 + index, &asVal);
          Scaleform::GFx::AS3::Value::~Value(&asVal);
          ++i;
          ++v7;
        }
        while ( v7 < count );
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
        v16 = retVal.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v16 )
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
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        parray.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(parray.pObject);
      }
    }
    _controlfp_s((unsigned int *)&result, dpg.fpc, 0x30000u);
    return 1;
  }
  else
  {
    *(_QWORD *)&val.value.VNumber = __PAIR64__(v36, (unsigned int)parray.pObject);
    val.Bonus.pWeakProxy = 0;
    val.Flags = 12;
    gfxval.pObjectInterface = 0;
    gfxval.Type = VT_Undefined;
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &val, (Scaleform::GFx::ASStringNode *)&gfxval);
    v19 = this->SetVariable(this, ppathToVar, &gfxval, setType);
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
        v20 = val.Bonus.pWeakProxy;
        --val.Bonus.pWeakProxy->RefCount;
        if ( !v20->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
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
        v21 = retVal.Bonus.pWeakProxy;
        v16 = retVal.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v16 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&retVal);
      }
    }
    _controlfp_s((unsigned int *)&result, dpg.fpc, 0x30000u);
    return v19;
  }
}
