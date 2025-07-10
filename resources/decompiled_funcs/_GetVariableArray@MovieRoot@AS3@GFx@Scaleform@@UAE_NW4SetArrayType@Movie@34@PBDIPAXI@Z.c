char __thiscall Scaleform::GFx::AS3::MovieRoot::GetVariableArray(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Movie::SetArrayType type,
        const char *ppathToVar,
        unsigned int index,
        const char *pdata,
        Scaleform::GFx::ASStringNode *count)
{
  Scaleform::GFx::AS3::Value::V1U v7; // ebx
  int v8; // eax
  int v9; // eax
  int *v10; // ebp
  unsigned int v11; // ebx
  unsigned int v12; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebp
  const Scaleform::GFx::AS3::Value *v15; // eax
  unsigned int v16; // esi
  const char *v17; // edi
  const Scaleform::GFx::AS3::Value *v18; // eax
  long double v19; // st7
  unsigned int v20; // esi
  unsigned int v21; // edi
  const char *v22; // ebp
  const Scaleform::GFx::AS3::Value *v23; // eax
  long double VNumber; // st7
  unsigned int v25; // ebp
  Scaleform::GFx::ASStringNode *v26; // esi
  Scaleform::GFx::AS3::Value *v27; // edi
  unsigned int v28; // eax
  unsigned int v29; // edi
  const char *v30; // ebx
  const Scaleform::GFx::AS3::Value *v31; // eax
  Scaleform::GFx::ASStringNode *VStr; // esi
  int v33; // eax
  Scaleform::GFx::ASString *v34; // ecx
  bool v35; // zf
  unsigned int v36; // eax
  int v37; // edi
  unsigned int i; // esi
  const Scaleform::GFx::AS3::Value *v39; // eax
  Scaleform::GFx::ASStringNode *v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // esi
  Scaleform::MemoryHeap_vtbl *v43; // edx
  int v44; // eax
  _WORD *v45; // esi
  unsigned int v46; // edi
  const char *v47; // ebx
  _WORD *v48; // ebp
  unsigned int v49; // eax
  void *pWeakProxy; // eax
  unsigned int _CurrentState; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::MovieRoot *v54; // [esp+14h] [ebp-14h]
  Scaleform::GFx::AS3::Value resolvedVal; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::Movie::SetArrayType typea; // [esp+2Ch] [ebp+4h]
  Scaleform::GFx::AS3::Impl::SparseArray *ppathToVara; // [esp+30h] [ebp+8h]

  v54 = this;
  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s(&_CurrentState, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  resolvedVal.Flags = 0;
  resolvedVal.Bonus.pWeakProxy = 0;
  if ( !Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &resolvedVal, ppathToVar) )
    goto LABEL_83;
  if ( (resolvedVal.Flags & 0x1F) - 12 > 3 )
  {
    Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
LABEL_88:
    _controlfp_s((unsigned int *)&pdata, dpg.fpc, 0x30000u);
    return 0;
  }
  v7 = resolvedVal.value.VS._1;
  if ( !resolvedVal.value.VS._1.VInt
    || (v8 = *(_DWORD *)(resolvedVal.value.VS._1.VInt + 20), *(_DWORD *)(v8 + 60) != 7)
    || (*(_DWORD *)(v8 + 56) & 0x20) != 0 )
  {
LABEL_83:
    if ( (resolvedVal.Flags & 0x1F) > 9 )
    {
      if ( (resolvedVal.Flags & 0x200) != 0 )
      {
        pWeakProxy = resolvedVal.Bonus.pWeakProxy;
        v35 = resolvedVal.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v35 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resolvedVal);
      }
    }
    goto LABEL_88;
  }
  Scaleform::GFx::MovieImpl::GetRetValHolder(this->pMovieImpl);
  v10 = (int *)v9;
  *(_DWORD *)(v9 + 24) = 0;
  _CurrentState = v9 + 8;
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)(v9 + 8),
    1u);
  ppathToVara = (Scaleform::GFx::AS3::Impl::SparseArray *)(v7.VInt + 32);
  v11 = *(_DWORD *)(v7.VInt + 32);
  v12 = (unsigned int)count;
  switch ( type )
  {
    case SA_Int:
      v13 = 0;
      v14 = v11;
      if ( v11 >= (unsigned int)count )
        v14 = (unsigned int)count;
      if ( v14 )
      {
        do
        {
          v15 = Scaleform::GFx::AS3::Impl::SparseArray::At(ppathToVara, v13 + index);
          if ( (v15->Flags & 0x1F) != 0 )
            *(_DWORD *)&pdata[4 * v13] = v15->value.VS._1.VInt;
          else
            *(_DWORD *)&pdata[4 * v13] = 0;
          ++v13;
        }
        while ( v13 < v14 );
        v12 = (unsigned int)count;
      }
      goto $LN331_1;
    case SA_Double:
      v20 = 0;
      v21 = v11;
      if ( v11 >= (unsigned int)count )
        v21 = (unsigned int)count;
      if ( v21 )
      {
        v22 = pdata;
        do
        {
          v23 = Scaleform::GFx::AS3::Impl::SparseArray::At(ppathToVara, v20 + index);
          if ( (v23->Flags & 0x1F) != 0 )
            VNumber = v23->value.VNumber;
          else
            VNumber = 0.0;
          *(long double *)&v22[8 * v20++] = VNumber;
        }
        while ( v20 < v21 );
      }
      break;
    case SA_Float:
$LN331_1:
      v16 = 0;
      if ( v11 >= v12 )
        v11 = v12;
      if ( v11 )
      {
        v17 = pdata;
        do
        {
          v18 = Scaleform::GFx::AS3::Impl::SparseArray::At(ppathToVara, v16 + index);
          if ( (v18->Flags & 0x1F) != 0 )
            v19 = v18->value.VNumber;
          else
            v19 = 0.0;
          *(float *)&v17[4 * v16++] = v19;
        }
        while ( v16 < v11 );
      }
      break;
    case SA_String:
      if ( v11 >= (unsigned int)count )
        v11 = (unsigned int)count;
      else
        count = (Scaleform::GFx::ASStringNode *)v11;
      v28 = 1;
      if ( v11 )
        v28 = v11;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)_CurrentState,
        v28);
      v29 = 0;
      if ( v11 )
      {
        v30 = pdata;
        do
        {
          v31 = Scaleform::GFx::AS3::Impl::SparseArray::At(ppathToVara, v29 + index);
          if ( (v31->Flags & 0x1F) != 0 )
          {
            VStr = v31->value.VS._1.VStr;
            ++VStr->RefCount;
            *(_DWORD *)&v30[4 * v29] = VStr->pData;
            v33 = v10[6];
            v10[6] = v33 + 1;
            v34 = (Scaleform::GFx::ASString *)(*(_DWORD *)_CurrentState + 4 * v33);
            pdata = (const char *)VStr;
            Scaleform::GFx::ASString::operator=(v34, (const Scaleform::GFx::ASString *)&pdata);
            v35 = VStr->RefCount-- == 1;
            if ( v35 )
              Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
          }
          else
          {
            *(_DWORD *)&v30[4 * v29] = 0;
          }
          ++v29;
        }
        while ( v29 < (unsigned int)count );
      }
      break;
    case SA_StringW:
      v36 = (unsigned int)count;
      v37 = 0;
      if ( v11 >= (unsigned int)count )
      {
        typea = (Scaleform::GFx::Movie::SetArrayType)count;
      }
      else
      {
        v36 = v11;
        typea = v11;
      }
      if ( !v36 )
        v36 = 1;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)_CurrentState,
        v36);
      for ( i = 0; i < v11; ++i )
      {
        v39 = Scaleform::GFx::AS3::Impl::SparseArray::At(ppathToVara, i + index);
        if ( (v39->Flags & 0x1F) != 0 )
        {
          count = v39->value.VS._1.VStr;
          ++count->RefCount;
          Scaleform::GFx::ASString::operator=(
            (Scaleform::GFx::ASString *)(*(_DWORD *)_CurrentState + 4 * i),
            (const Scaleform::GFx::ASString *)&count);
          v37 += Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&count) + 1;
          v40 = count;
          --count->RefCount;
          if ( !v40->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v40);
        }
      }
      v41 = v10[1];
      v42 = (2 * v37 + 4095) & 0xFFFFF000;
      if ( v41 < v42 || v41 > v42 && v41 - v42 > 0x1000 )
      {
        v43 = Scaleform::Memory::pGlobalHeap->__vftable;
        if ( *v10 )
          v44 = ((int (__stdcall *)(int, unsigned int))v43->Realloc)(*v10, (2 * v37 + 4095) & 0xFFFFF000);
        else
          v44 = ((int (__stdcall *)(unsigned int, _DWORD))v43->Alloc)((2 * v37 + 4095) & 0xFFFFF000, 0);
        *v10 = v44;
        v10[1] = v42;
      }
      v45 = (_WORD *)*v10;
      v46 = 0;
      if ( typea )
      {
        v47 = pdata;
        do
        {
          pdata = **(const char ***)(*(_DWORD *)_CurrentState + 4 * v46);
          v48 = v45;
          while ( 1 )
          {
            v49 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&pdata);
            if ( !v49 )
              break;
            *v45++ = v49;
          }
          --pdata;
          *v45 = 0;
          *(_DWORD *)&v47[4 * v46++] = v48;
          ++v45;
        }
        while ( v46 < typea );
      }
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)_CurrentState,
        1u);
      break;
    case SA_Value:
      v25 = 0;
      if ( v11 >= (unsigned int)count )
        v11 = (unsigned int)count;
      if ( v11 )
      {
        v26 = (Scaleform::GFx::ASStringNode *)pdata;
        do
        {
          v27 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(ppathToVara, index + v25);
          if ( ((int)v26->pManager & 0x40) != 0 )
          {
            (*(void (__stdcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::ASStringNode *))(*(_DWORD *)v26->pData
                                                                                                  + 8))(
              v26,
              v26->pLower);
            v26->pData = 0;
          }
          v26->pManager = 0;
          if ( (v27->Flags & 0x1F) != 0 )
            Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v54, v27, v26);
          else
            v26->pManager = 0;
          ++v25;
          ++v26;
        }
        while ( v25 < v11 );
      }
      break;
    default:
      break;
  }
  Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
  _controlfp_s((unsigned int *)&pdata, dpg.fpc, 0x30000u);
  return 1;
}
