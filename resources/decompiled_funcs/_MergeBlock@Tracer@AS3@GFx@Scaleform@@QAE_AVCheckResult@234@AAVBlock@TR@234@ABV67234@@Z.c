Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Tracer::MergeBlock(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::TR::Block *to,
        const Scaleform::GFx::AS3::TR::Block *from)
{
  unsigned int v4; // eax
  int v5; // esi
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v6; // ecx
  Scaleform::GFx::AS3::Value *v7; // ebp
  int v8; // eax
  const Scaleform::GFx::AS3::Value *v9; // edi
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // ebx
  Scaleform::GFx::AS3::VM *v11; // eax
  int v12; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v13; // esi
  Scaleform::GFx::AS3::VM *v14; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v15; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *j; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v17; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *k; // eax
  Scaleform::GFx::AS3::VM *v19; // esi
  const Scaleform::GFx::AS3::VM::Error *v20; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v22; // edi
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v23; // esi
  int v24; // ebx
  Scaleform::GFx::AS3::Value *v25; // edi
  int v26; // eax
  const Scaleform::GFx::AS3::Value *v27; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v28; // eax
  Scaleform::GFx::AS3::VM *v29; // ecx
  int v30; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v31; // ebp
  Scaleform::GFx::AS3::VM *v32; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v33; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v34; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v35; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *m; // eax
  Scaleform::GFx::AS3::VM *v37; // esi
  const Scaleform::GFx::AS3::VM::Error *v38; // eax
  Scaleform::GFx::ASStringNode *v39; // eax
  Scaleform::GFx::AS3::VM *v40; // esi
  const Scaleform::GFx::AS3::VM::Error *v41; // eax
  Scaleform::GFx::ASStringNode *v42; // eax
  Scaleform::GFx::AS3::CheckResult *v43; // eax
  Scaleform::GFx::AS3::TR::State *v44; // edx
  unsigned int Size; // eax
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // esi
  unsigned int v47; // ecx
  int v48; // ebp
  Scaleform::GFx::AS3::Value *v49; // edi
  int v50; // eax
  const Scaleform::GFx::AS3::Value *v51; // esi
  int v52; // eax
  Scaleform::GFx::AS3::VM *VMRef; // eax
  int v54; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // ebp
  Scaleform::GFx::AS3::VM *v56; // eax
  int v57; // edx
  unsigned __int8 *pData; // ecx
  Scaleform::GFx::AS3::VM *v59; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v61; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v62; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *i; // eax
  bool v64; // dl
  Scaleform::GFx::AS3::Traits *tr; // [esp+14h] [ebp-30h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *tra; // [esp+14h] [ebp-30h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *trb; // [esp+14h] [ebp-30h]
  Scaleform::GFx::AS3::TR::State *from_st; // [esp+18h] [ebp-2Ch]
  Scaleform::GFx::AS3::VM *v70; // [esp+1Ch] [ebp-28h]
  Scaleform::GFx::AS3::VM *v71; // [esp+1Ch] [ebp-28h]
  int v72; // [esp+1Ch] [ebp-28h]
  Scaleform::GFx::AS3::TR::State *to_st; // [esp+20h] [ebp-24h]
  int v74; // [esp+24h] [ebp-20h]
  unsigned int v75; // [esp+24h] [ebp-20h]
  unsigned int v76; // [esp+24h] [ebp-20h]
  int v77; // [esp+28h] [ebp-1Ch]
  int v78; // [esp+28h] [ebp-1Ch]
  char v79; // [esp+28h] [ebp-1Ch]
  int v80; // [esp+2Ch] [ebp-18h]
  int v81; // [esp+2Ch] [ebp-18h]
  int v82; // [esp+2Ch] [ebp-18h]
  int v83; // [esp+30h] [ebp-14h]
  int v84; // [esp+30h] [ebp-14h]
  unsigned __int8 v85; // [esp+38h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v86; // [esp+3Ch] [ebp-8h] BYREF
  Scaleform::GFx::AS3::InstanceTraits::Traits *toa; // [esp+4Ch] [ebp+8h]
  bool tob; // [esp+4Ch] [ebp+8h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *toc; // [esp+4Ch] [ebp+8h]
  bool tod; // [esp+4Ch] [ebp+8h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *toe; // [esp+4Ch] [ebp+8h]
  bool tof; // [esp+4Ch] [ebp+8h]
  char froma; // [esp+50h] [ebp+Ch]
  char fromb; // [esp+50h] [ebp+Ch]
  char fromc; // [esp+50h] [ebp+Ch]

  from_st = from->State;
  to_st = to->State;
  if ( (to->Type & 4) != 0 )
  {
LABEL_129:
    v44 = from_st;
    Size = from_st->Registers.Data.Size;
    p_Data = &to_st->Registers.Data;
    if ( to_st->Registers.Data.Size != Size )
      goto LABEL_117;
    v47 = 0;
    v76 = 0;
    if ( !Size )
    {
LABEL_199:
      v43 = result;
      result->Result = 1;
      return v43;
    }
    v48 = 0;
    v72 = 0;
    while ( v47 >= p_Data->Size )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        p_Data,
        (Scaleform::GFx::AS3::Value *)((char *)v44->Registers.Data.Data + v48));
LABEL_198:
      v44 = from_st;
      v47 = v76 + 1;
      v48 += 16;
      v76 = v47;
      v72 = v48;
      if ( v47 >= from_st->Registers.Data.Size )
        goto LABEL_199;
    }
    v49 = (Scaleform::GFx::AS3::Value *)((char *)p_Data->Data + v48);
    v50 = v49->Flags & 0x1F;
    v51 = (Scaleform::GFx::AS3::Value *)((char *)from_st->Registers.Data.Data + v48);
    v84 = v50;
    if ( v50 )
    {
      v52 = v50 - 8;
      if ( v52 )
      {
        if ( v52 == 1 )
          trb = v49->value.VS._1.ITr;
        else
          trb = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                 this->CF->pFile->VMRef,
                                                                 v49);
      }
      else
      {
        trb = v49->value.VS._1.ITr;
      }
    }
    else
    {
      trb = this->CF->pFile->VMRef->TraitsVoid.pObject;
    }
    if ( trb )
    {
      VMRef = this->CF->pFile->VMRef;
      if ( trb == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
        trb = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
    }
    v54 = v51->Flags & 0x1F;
    v82 = v54;
    if ( v54 )
    {
      if ( (unsigned int)(v54 - 8) < 2 )
        ITr = v51->value.VS._1.ITr;
      else
        ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                               this->CF->pFile->VMRef,
                                                               v51);
    }
    else
    {
      ITr = this->CF->pFile->VMRef->TraitsVoid.pObject;
    }
    if ( ITr )
    {
      v56 = this->CF->pFile->VMRef;
      if ( ITr == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v56->TraitsClassClass.pObject )
        ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v56->TraitsObject.pObject;
    }
    v57 = 1 << (v76 & 7);
    v79 = v76 & 7;
    pData = from_st->RegistersAlive.pData;
    fromc = 0;
    v86.ID = v76 >> 3;
    v85 = v57;
    if ( ((unsigned __int8)v57 & pData[v76 >> 3]) != 0 )
    {
      if ( ((unsigned __int8)v57 & to_st->RegistersAlive.pData[v76 >> 3]) == 0 )
        goto LABEL_190;
      if ( trb == ITr )
        goto LABEL_191;
      if ( !v84 )
        goto LABEL_190;
      v59 = this->CF->pFile->VMRef;
      toe = v59->TraitsObject.pObject->ITraits.pObject;
      if ( trb == toe || trb == v59->TraitsClassClass.pObject->ITraits.pObject )
        goto LABEL_191;
      if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, ITr) )
      {
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v49, v51, toe);
        goto LABEL_191;
      }
      tof = Scaleform::GFx::AS3::Tracer::IsNumericType(this, trb);
      if ( tof && Scaleform::GFx::AS3::Tracer::IsNumericType(this, ITr) )
      {
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v49, v51, v59->TraitsNumber.pObject->ITraits.pObject);
        goto LABEL_191;
      }
      if ( (unsigned int)(v84 - 12) > 3 || v49->value.VS._1.VInt )
      {
        pObject = v59->TraitsNull.pObject;
        v61 = trb;
        if ( trb != pObject )
        {
          if ( (unsigned int)(v82 - 12) <= 3 && !v51->value.VS._1.VInt || ITr == pObject )
          {
            if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, trb) && tof )
              goto LABEL_181;
          }
          else
          {
            if ( trb )
            {
              do
              {
                v61->Flags |= 0x80u;
                v61 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v61->pParent.pObject;
              }
              while ( v61 );
            }
            v62 = (Scaleform::GFx::AS3::ClassTraits::Traits *)ITr;
            if ( ITr )
            {
              while ( (v62->Flags & 0x80) == 0 )
              {
                v62 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v62->pParent.pObject;
                if ( !v62 )
                  goto LABEL_178;
              }
              fromc = 1;
              if ( (v62->Flags & 0x20) != 0 )
                Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v49, v51, v62);
              else
                Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
                  this,
                  v49,
                  v51,
                  (Scaleform::GFx::AS3::InstanceTraits::Traits *)v62);
            }
LABEL_178:
            for ( i = trb; i; i = (Scaleform::GFx::AS3::InstanceTraits::Traits *)i->pParent.pObject )
              i->Flags &= ~0x80u;
            if ( !fromc )
            {
LABEL_181:
              v40 = this->CF->pFile->VMRef;
              Scaleform::GFx::AS3::VM::Error::Error(&v86, eCannotMergeTypesError, v40);
              goto LABEL_115;
            }
          }
          goto LABEL_191;
        }
      }
      if ( ((unsigned int)(v82 - 12) > 3 || v51->value.VS._1.VInt) && ITr != v59->TraitsNull.pObject )
      {
        if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, ITr)
          && Scaleform::GFx::AS3::Tracer::IsNumericType(this, ITr) )
        {
          goto LABEL_181;
        }
LABEL_190:
        Scaleform::GFx::AS3::Value::Assign(v49, v51);
      }
    }
LABEL_191:
    v64 = (v85 & from_st->RegistersAlive.pData[v86.ID]) != 0 || (v85 & to_st->RegistersAlive.pData[v86.ID]) != 0;
    v48 = v72;
    p_Data = &to_st->Registers.Data;
    if ( v64 )
      to_st->RegistersAlive.pData[v86.ID] |= 1 << v79;
    else
      to_st->RegistersAlive.pData[v86.ID] &= ~(1 << v79);
    goto LABEL_198;
  }
  v4 = from->State->OpStack.Data.Size;
  if ( to->State->OpStack.Data.Size != v4 )
    goto LABEL_52;
  tr = 0;
  if ( !v4 )
    goto LABEL_52;
  v5 = 0;
  v74 = 0;
  while ( 1 )
  {
    v6 = &to_st->OpStack.Data;
    if ( (unsigned int)tr < to_st->OpStack.Data.Size )
      break;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      v6,
      (Scaleform::GFx::AS3::Value *)((char *)from_st->OpStack.Data.Data + v5));
LABEL_66:
    v5 += 16;
    tr = (Scaleform::GFx::AS3::Traits *)((char *)tr + 1);
    v74 = v5;
    if ( (unsigned int)tr >= from_st->OpStack.Data.Size )
      goto LABEL_52;
  }
  v7 = (Scaleform::GFx::AS3::Value *)((char *)v6->Data + v5);
  v8 = v7->Flags & 0x1F;
  v9 = (Scaleform::GFx::AS3::Value *)((char *)from_st->OpStack.Data.Data + v5);
  v77 = v8;
  if ( v8 )
  {
    if ( (unsigned int)(v8 - 8) < 2 )
      ValueTraits = v7->value.VS._1.ITr;
    else
      ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                     this->CF->pFile->VMRef,
                                                                     v7);
  }
  else
  {
    ValueTraits = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( ValueTraits )
  {
    v11 = this->CF->pFile->VMRef;
    if ( ValueTraits == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v11->TraitsClassClass.pObject )
      ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v11->TraitsObject.pObject;
  }
  v12 = v9->Flags & 0x1F;
  v80 = v12;
  if ( v12 )
  {
    if ( (unsigned int)(v12 - 8) < 2 )
      v13 = v9->value.VS._1.ITr;
    else
      v13 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v9);
  }
  else
  {
    v13 = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v13 )
  {
    v14 = this->CF->pFile->VMRef;
    if ( v13 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v14->TraitsClassClass.pObject )
      v13 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v14->TraitsObject.pObject;
  }
  froma = 0;
  if ( ValueTraits == v13 )
  {
LABEL_65:
    v5 = v74;
    goto LABEL_66;
  }
  if ( !v77 )
  {
LABEL_64:
    Scaleform::GFx::AS3::Value::Assign(v7, v9);
    goto LABEL_65;
  }
  v70 = this->CF->pFile->VMRef;
  toa = v70->TraitsObject.pObject->ITraits.pObject;
  if ( ValueTraits == toa || ValueTraits == v70->TraitsClassClass.pObject->ITraits.pObject )
    goto LABEL_65;
  if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, v13) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v7, v9, toa);
    goto LABEL_65;
  }
  tob = Scaleform::GFx::AS3::Tracer::IsNumericType(this, ValueTraits);
  if ( tob && Scaleform::GFx::AS3::Tracer::IsNumericType(this, v13) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v7, v9, v70->TraitsNumber.pObject->ITraits.pObject);
    goto LABEL_65;
  }
  if ( (unsigned int)(v77 - 12) <= 3 && !v7->value.VS._1.VInt || (v15 = v70->TraitsNull.pObject, ValueTraits == v15) )
  {
    if ( (unsigned int)(v80 - 12) <= 3 && !v9->value.VS._1.VInt || v13 == v70->TraitsNull.pObject )
      goto LABEL_65;
    if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, v13) && Scaleform::GFx::AS3::Tracer::IsNumericType(this, v13) )
      goto LABEL_50;
    goto LABEL_64;
  }
  if ( (unsigned int)(v80 - 12) <= 3 && !v9->value.VS._1.VInt || v13 == v15 )
  {
    if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, ValueTraits) && tob )
      goto LABEL_50;
    goto LABEL_65;
  }
  for ( j = ValueTraits; j; j = (Scaleform::GFx::AS3::InstanceTraits::Traits *)j->pParent.pObject )
    j->Flags |= 0x80u;
  v17 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v13;
  if ( v13 )
  {
    while ( (v17->Flags & 0x80) == 0 )
    {
      v17 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v17->pParent.pObject;
      if ( !v17 )
        goto LABEL_47;
    }
    froma = 1;
    if ( (v17->Flags & 0x20) != 0 )
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v7, v9, v17);
    else
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
        this,
        v7,
        v9,
        (Scaleform::GFx::AS3::InstanceTraits::Traits *)v17);
  }
LABEL_47:
  for ( k = ValueTraits; k; k = (Scaleform::GFx::AS3::InstanceTraits::Traits *)k->pParent.pObject )
    k->Flags &= ~0x80u;
  if ( froma )
    goto LABEL_65;
LABEL_50:
  v19 = this->CF->pFile->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v86, eCannotMergeTypesError, v19);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v19,
    v20,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pNode = v86.Message.pNode;
  --v86.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_52:
  v22 = 0;
  v23 = &to_st->ScopeStack.Data;
  v75 = 0;
  if ( !from_st->ScopeStack.Data.Size )
    goto LABEL_129;
  v24 = 0;
  v83 = 0;
  while ( v22 >= v23->Size )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      v23,
      (Scaleform::GFx::AS3::Value *)((char *)from_st->ScopeStack.Data.Data + v24));
LABEL_128:
    ++v22;
    v24 += 16;
    v75 = v22;
    v83 = v24;
    if ( v22 >= from_st->ScopeStack.Data.Size )
      goto LABEL_129;
  }
  v25 = (Scaleform::GFx::AS3::Value *)((char *)v23->Data + v24);
  v26 = v25->Flags & 0x1F;
  v27 = (Scaleform::GFx::AS3::Value *)((char *)from_st->ScopeStack.Data.Data + v24);
  v81 = v26;
  if ( v26 )
  {
    if ( (unsigned int)(v26 - 8) < 2 )
      v28 = v25->value.VS._1.ITr;
    else
      v28 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v25);
  }
  else
  {
    v28 = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  tra = v28;
  if ( v28 )
  {
    v29 = this->CF->pFile->VMRef;
    if ( v28 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v29->TraitsClassClass.pObject )
      tra = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v29->TraitsObject.pObject;
  }
  v30 = v27->Flags & 0x1F;
  v78 = v30;
  if ( v30 )
  {
    if ( (unsigned int)(v30 - 8) < 2 )
      v31 = v27->value.VS._1.ITr;
    else
      v31 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v27);
  }
  else
  {
    v31 = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v31 )
  {
    v32 = this->CF->pFile->VMRef;
    if ( v31 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v32->TraitsClassClass.pObject )
      v31 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v32->TraitsObject.pObject;
  }
  fromb = 0;
  if ( (((unsigned __int8)BYTE1(v25->Flags) ^ (unsigned __int8)BYTE1(v27->Flags)) & 1) != 0 )
    goto LABEL_112;
  if ( tra == v31 )
    goto LABEL_127;
  if ( !v81 )
  {
LABEL_126:
    Scaleform::GFx::AS3::Value::Assign(v25, v27);
    goto LABEL_127;
  }
  v71 = this->CF->pFile->VMRef;
  toc = v71->TraitsObject.pObject->ITraits.pObject;
  if ( tra == toc || tra == v71->TraitsClassClass.pObject->ITraits.pObject )
    goto LABEL_127;
  if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, v31) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v25, v27, toc);
    goto LABEL_127;
  }
  tod = Scaleform::GFx::AS3::Tracer::IsNumericType(this, tra);
  if ( tod && Scaleform::GFx::AS3::Tracer::IsNumericType(this, v31) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v25, v27, v71->TraitsNumber.pObject->ITraits.pObject);
    goto LABEL_127;
  }
  if ( (unsigned int)(v81 - 12) <= 3 && !v25->value.VS._1.VInt || (v33 = v71->TraitsNull.pObject, v34 = tra, tra == v33) )
  {
    if ( (unsigned int)(v78 - 12) <= 3 && !v27->value.VS._1.VInt || v31 == v71->TraitsNull.pObject )
      goto LABEL_127;
    if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, v31) && Scaleform::GFx::AS3::Tracer::IsNumericType(this, v31) )
      goto LABEL_112;
    goto LABEL_126;
  }
  if ( (unsigned int)(v78 - 12) <= 3 && !v27->value.VS._1.VInt || v31 == v33 )
  {
    if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, tra) && tod )
      goto LABEL_112;
    goto LABEL_127;
  }
  if ( tra )
  {
    do
    {
      v34->Flags |= 0x80u;
      v34 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v34->pParent.pObject;
    }
    while ( v34 );
  }
  v35 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v31;
  if ( v31 )
  {
    while ( (v35->Flags & 0x80) == 0 )
    {
      v35 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v35->pParent.pObject;
      if ( !v35 )
        goto LABEL_109;
    }
    fromb = 1;
    if ( (v35->Flags & 0x20) != 0 )
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v25, v27, v35);
    else
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
        this,
        v25,
        v27,
        (Scaleform::GFx::AS3::InstanceTraits::Traits *)v35);
  }
LABEL_109:
  for ( m = tra; m; m = (Scaleform::GFx::AS3::InstanceTraits::Traits *)m->pParent.pObject )
    m->Flags &= ~0x80u;
  if ( fromb )
  {
LABEL_127:
    v24 = v83;
    v22 = v75;
    v23 = &to_st->ScopeStack.Data;
    goto LABEL_128;
  }
LABEL_112:
  v37 = this->CF->pFile->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v86, eCannotMergeTypesError, v37);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v37,
    v38,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v39 = v86.Message.pNode;
  --v86.Message.pNode->RefCount;
  if ( !v39->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  v40 = this->CF->pFile->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v86, eScopeDepthUnbalancedError, v40);
LABEL_115:
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v40,
    v41,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v42 = v86.Message.pNode;
  --v86.Message.pNode->RefCount;
  if ( !v42->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
LABEL_117:
  v43 = result;
  result->Result = 0;
  return v43;
}
