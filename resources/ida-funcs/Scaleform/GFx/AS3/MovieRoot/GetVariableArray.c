char __userpurge Scaleform::GFx::AS3::MovieRoot::GetVariableArray@<al>(
        Scaleform::GFx::AS3::MovieRoot *this@<ecx>,
        int VInt@<ebx>,
        Scaleform::GFx::Movie::SetArrayType type,
        const char *ppathToVar,
        Scaleform::GFx::ASStringNode *index,
        const char *pdata,
        Scaleform::GFx::ASStringNode *count)
{
  int v8; // eax
  int v9; // eax
  int *v10; // ebp
  Scaleform::GFx::ASStringNode *v11; // ebx
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
  const Scaleform::GFx::AS3::Value *v30; // eax
  Scaleform::GFx::ASStringNode *VStr; // esi
  int v32; // eax
  Scaleform::GFx::ASString *v33; // ecx
  bool v34; // zf
  unsigned int v35; // eax
  int v36; // edi
  unsigned int v37; // esi
  const Scaleform::GFx::AS3::Value *v38; // eax
  Scaleform::GFx::ASStringNode *v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // esi
  Scaleform::MemoryHeap_vtbl *v42; // edx
  int v43; // eax
  _WORD *v44; // esi
  unsigned int v45; // edi
  _WORD *v46; // ebp
  unsigned int v47; // eax
  void *pWeakProxy; // eax
  unsigned int _CurrentState; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::MovieRoot *v52; // [esp+14h] [ebp-14h]
  Scaleform::GFx::AS3::Value resolvedVal; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::Movie::SetArrayType typea; // [esp+2Ch] [ebp+4h]
  Scaleform::GFx::AS3::Impl::SparseArray *ppathToVara; // [esp+30h] [ebp+8h]

  v52 = this;
  _controlfp_s(VInt, &dpg.fpc, 0, 0);
  _controlfp_s(VInt, &_CurrentState, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  resolvedVal.Flags = 0;
  resolvedVal.Bonus.pWeakProxy = 0;
  if ( !Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &resolvedVal, ppathToVar) )
    goto LABEL_83;
  if ( (resolvedVal.Flags & 0x1F) - 12 > 3 )
  {
    Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
LABEL_88:
    _controlfp_s(VInt, (unsigned int *)&pdata, dpg.fpc, (unsigned int)&loc_30000);
    return 0;
  }
  VInt = resolvedVal.value.VS._1.VInt;
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
        v34 = resolvedVal.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v34 )
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
  ppathToVara = (Scaleform::GFx::AS3::Impl::SparseArray *)(VInt + 32);
  v11 = *(Scaleform::GFx::ASStringNode **)(VInt + 32);
  v12 = (unsigned int)count;
  switch ( type )
  {
    case SA_Int:
      v13 = 0;
      v14 = (unsigned int)v11;
      if ( v11 >= count )
        v14 = (unsigned int)count;
      if ( v14 )
      {
        do
        {
          v15 = Scaleform::GFx::AS3::Impl::SparseArray::At(ppathToVara, (unsigned int)index + v13);
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
      v21 = (unsigned int)v11;
      if ( v11 >= count )
        v21 = (unsigned int)count;
      if ( v21 )
      {
        v22 = pdata;
        v11 = index;
        do
        {
          v23 = Scaleform::GFx::AS3::Impl::SparseArray::At(ppathToVara, (unsigned int)index + v20);
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
      if ( (unsigned int)v11 >= v12 )
        v11 = (Scaleform::GFx::ASStringNode *)v12;
      if ( v11 )
      {
        v17 = pdata;
        do
        {
          v18 = Scaleform::GFx::AS3::Impl::SparseArray::At(ppathToVara, (unsigned int)index + v16);
          if ( (v18->Flags & 0x1F) != 0 )
            v19 = v18->value.VNumber;
          else
            v19 = 0.0;
          *(float *)&v17[4 * v16++] = v19;
        }
        while ( v16 < (unsigned int)v11 );
      }
      break;
    case SA_String:
      if ( v11 >= count )
        v11 = count;
      else
        count = v11;
      v28 = 1;
      if ( v11 )
        v28 = (unsigned int)v11;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)_CurrentState,
        v28);
      v29 = 0;
      if ( v11 )
      {
        v11 = (Scaleform::GFx::ASStringNode *)pdata;
        do
        {
          v30 = Scaleform::GFx::AS3::Impl::SparseArray::At(ppathToVara, (unsigned int)index + v29);
          if ( (v30->Flags & 0x1F) != 0 )
          {
            VStr = v30->value.VS._1.VStr;
            ++VStr->RefCount;
            *((_DWORD *)&v11->pData + v29) = VStr->pData;
            v32 = v10[6];
            v10[6] = v32 + 1;
            v33 = (Scaleform::GFx::ASString *)(*(_DWORD *)_CurrentState + 4 * v32);
            pdata = (const char *)VStr;
            Scaleform::GFx::ASString::operator=(v33, (const Scaleform::GFx::ASString *)&pdata);
            v34 = VStr->RefCount-- == 1;
            if ( v34 )
              Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
          }
          else
          {
            *((_DWORD *)&v11->pData + v29) = 0;
          }
          ++v29;
        }
        while ( v29 < (unsigned int)count );
      }
      break;
    case SA_StringW:
      v35 = (unsigned int)count;
      v36 = 0;
      if ( v11 >= count )
      {
        typea = (Scaleform::GFx::Movie::SetArrayType)count;
      }
      else
      {
        v35 = (unsigned int)v11;
        typea = (Scaleform::GFx::Movie::SetArrayType)v11;
      }
      if ( !v35 )
        v35 = 1;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)_CurrentState,
        v35);
      v37 = 0;
      if ( v11 )
      {
        do
        {
          v38 = Scaleform::GFx::AS3::Impl::SparseArray::At(ppathToVara, (unsigned int)index + v37);
          if ( (v38->Flags & 0x1F) != 0 )
          {
            count = v38->value.VS._1.VStr;
            ++count->RefCount;
            Scaleform::GFx::ASString::operator=(
              (Scaleform::GFx::ASString *)(*(_DWORD *)_CurrentState + 4 * v37),
              (const Scaleform::GFx::ASString *)&count);
            v36 += Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&count) + 1;
            v39 = count;
            --count->RefCount;
            if ( !v39->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v39);
          }
          ++v37;
        }
        while ( v37 < (unsigned int)v11 );
      }
      v40 = v10[1];
      v41 = (2 * v36 + 4095) & 0xFFFFF000;
      if ( v40 < v41 || v40 > v41 && v40 - v41 > 0x1000 )
      {
        v42 = Scaleform::Memory::pGlobalHeap->__vftable;
        if ( *v10 )
          v43 = ((int (__stdcall *)(int, unsigned int))v42->Realloc)(*v10, (2 * v36 + 4095) & 0xFFFFF000);
        else
          v43 = ((int (__stdcall *)(unsigned int, _DWORD))v42->Alloc)((2 * v36 + 4095) & 0xFFFFF000, 0);
        *v10 = v43;
        v10[1] = v41;
      }
      v44 = (_WORD *)*v10;
      v45 = 0;
      if ( typea )
      {
        v11 = (Scaleform::GFx::ASStringNode *)pdata;
        do
        {
          pdata = **(const char ***)(*(_DWORD *)_CurrentState + 4 * v45);
          v46 = v44;
          while ( 1 )
          {
            v47 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&pdata);
            if ( !v47 )
              break;
            *v44++ = v47;
          }
          --pdata;
          *v44 = 0;
          *((_DWORD *)&v11->pData + v45++) = v46;
          ++v44;
        }
        while ( v45 < typea );
      }
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)_CurrentState,
        1u);
      break;
    case SA_Value:
      v25 = 0;
      if ( v11 >= count )
        v11 = count;
      if ( v11 )
      {
        v26 = (Scaleform::GFx::ASStringNode *)pdata;
        do
        {
          v27 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(
                                                ppathToVara,
                                                (unsigned int)index + v25);
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
            Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v52, v27, v26);
          else
            v26->pManager = 0;
          ++v25;
          ++v26;
        }
        while ( v25 < (unsigned int)v11 );
      }
      break;
    default:
      break;
  }
  Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
  _controlfp_s((int)v11, (unsigned int *)&pdata, dpg.fpc, (unsigned int)&loc_30000);
  return 1;
}
