void __thiscall Scaleform::GFx::AS3::Tracer::InitializeBlock(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::Block *to,
        const Scaleform::GFx::AS3::TR::Block *from)
{
  int v3; // esi
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // ecx
  Scaleform::GFx::AS3::Value *v5; // ebp
  int v6; // eax
  const Scaleform::GFx::AS3::Value *v7; // edi
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // ebx
  Scaleform::GFx::AS3::VM *VMRef; // eax
  int v10; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // esi
  Scaleform::GFx::AS3::VM *v12; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *i; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v15; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *j; // eax
  Scaleform::GFx::AS3::VM *v17; // esi
  const Scaleform::GFx::AS3::VM::Error *v18; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v20; // edi
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v21; // esi
  int v22; // ebx
  Scaleform::GFx::AS3::Value *v23; // edi
  int v24; // eax
  const Scaleform::GFx::AS3::Value *v25; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v26; // ebx
  Scaleform::GFx::AS3::VM *v27; // eax
  int v28; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v29; // ebp
  Scaleform::GFx::AS3::VM *v30; // eax
  Scaleform::GFx::AS3::VM *v31; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v32; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v33; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v34; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *k; // eax
  Scaleform::GFx::AS3::VM *v36; // esi
  const Scaleform::GFx::AS3::VM::Error *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::AS3::TR::State *v39; // esi
  unsigned int Size; // eax
  unsigned int v41; // edx
  int v42; // ebp
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v43; // ecx
  Scaleform::GFx::AS3::Value *v44; // edi
  int v45; // eax
  const Scaleform::GFx::AS3::Value *v46; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v47; // ebx
  Scaleform::GFx::AS3::VM *v48; // eax
  int v49; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v50; // ebp
  Scaleform::GFx::AS3::VM *v51; // eax
  int v52; // edx
  unsigned __int8 *pData; // ecx
  Scaleform::GFx::AS3::VM *v54; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v55; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v56; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v57; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *m; // eax
  Scaleform::GFx::AS3::VM *v59; // esi
  const Scaleform::GFx::AS3::VM::Error *v60; // eax
  Scaleform::GFx::ASStringNode *v61; // eax
  bool v62; // cl
  Scaleform::GFx::AS3::TR::State *from_st; // [esp+14h] [ebp-30h]
  Scaleform::GFx::AS3::VM *tr; // [esp+18h] [ebp-2Ch]
  Scaleform::GFx::AS3::InstanceTraits::Traits *tra; // [esp+18h] [ebp-2Ch]
  Scaleform::GFx::AS3::InstanceTraits::Traits *trb; // [esp+18h] [ebp-2Ch]
  Scaleform::GFx::AS3::TR::State *to_st; // [esp+1Ch] [ebp-28h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *result_type; // [esp+20h] [ebp-24h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *result_typea; // [esp+20h] [ebp-24h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *result_typeb; // [esp+20h] [ebp-24h]
  unsigned int v72; // [esp+24h] [ebp-20h]
  int v73; // [esp+24h] [ebp-20h]
  int v74; // [esp+24h] [ebp-20h]
  int v75; // [esp+28h] [ebp-1Ch]
  unsigned int v76; // [esp+28h] [ebp-1Ch]
  unsigned int v77; // [esp+28h] [ebp-1Ch]
  int v78; // [esp+2Ch] [ebp-18h]
  int v79; // [esp+2Ch] [ebp-18h]
  int v80; // [esp+2Ch] [ebp-18h]
  int v81; // [esp+30h] [ebp-14h]
  int v82; // [esp+30h] [ebp-14h]
  int v83; // [esp+30h] [ebp-14h]
  unsigned __int8 v84; // [esp+34h] [ebp-10h]
  char v85; // [esp+38h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v86; // [esp+3Ch] [ebp-8h] BYREF
  char froma; // [esp+4Ch] [ebp+8h]
  char fromb; // [esp+4Ch] [ebp+8h]
  char fromc; // [esp+4Ch] [ebp+8h]

  from_st = from->State;
  to_st = to->State;
  v72 = 0;
  if ( !from_st->OpStack.Data.Size )
    goto LABEL_50;
  v3 = 0;
  v75 = 0;
  while ( 1 )
  {
    p_Data = &to_st->OpStack.Data;
    if ( v72 < to_st->OpStack.Data.Size )
      break;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      p_Data,
      (Scaleform::GFx::AS3::Value *)((char *)from_st->OpStack.Data.Data + v3));
LABEL_64:
    v3 += 16;
    ++v72;
    v75 = v3;
    if ( v72 >= from_st->OpStack.Data.Size )
      goto LABEL_50;
  }
  v5 = (Scaleform::GFx::AS3::Value *)((char *)p_Data->Data + v3);
  v6 = v5->Flags & 0x1F;
  v7 = (Scaleform::GFx::AS3::Value *)((char *)from_st->OpStack.Data.Data + v3);
  v78 = v6;
  if ( v6 )
  {
    if ( (unsigned int)(v6 - 8) < 2 )
      ITr = v5->value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v5);
  }
  else
  {
    ITr = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( ITr )
  {
    VMRef = this->CF->pFile->VMRef;
    if ( ITr == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
  }
  v10 = v7->Flags & 0x1F;
  v81 = v10;
  if ( v10 )
  {
    if ( (unsigned int)(v10 - 8) < 2 )
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
    v12 = this->CF->pFile->VMRef;
    if ( ValueTraits == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v12->TraitsClassClass.pObject )
      ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v12->TraitsObject.pObject;
  }
  froma = 0;
  if ( ITr == ValueTraits )
    goto LABEL_63;
  if ( !v78 )
  {
LABEL_62:
    Scaleform::GFx::AS3::Value::Assign(v5, v7);
    goto LABEL_63;
  }
  tr = this->CF->pFile->VMRef;
  result_type = tr->TraitsObject.pObject->ITraits.pObject;
  if ( ITr == result_type || ITr == tr->TraitsClassClass.pObject->ITraits.pObject )
    goto LABEL_63;
  if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, ValueTraits) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v5, v7, result_type);
    goto LABEL_63;
  }
  if ( Scaleform::GFx::AS3::Tracer::IsNumericType(this, ITr)
    && Scaleform::GFx::AS3::Tracer::IsNumericType(this, ValueTraits) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v5, v7, tr->TraitsNumber.pObject->ITraits.pObject);
    goto LABEL_63;
  }
  if ( (unsigned int)(v78 - 12) <= 3 && !v5->value.VS._1.VInt || (pObject = tr->TraitsNull.pObject, ITr == pObject) )
  {
    if ( (unsigned int)(v81 - 12) <= 3 && !v7->value.VS._1.VInt || ValueTraits == tr->TraitsNull.pObject )
      goto LABEL_63;
    if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, ValueTraits)
      && Scaleform::GFx::AS3::Tracer::IsNumericType(this, ValueTraits) )
    {
      goto LABEL_48;
    }
    goto LABEL_62;
  }
  if ( (unsigned int)(v81 - 12) <= 3 && !v7->value.VS._1.VInt || ValueTraits == pObject )
  {
    if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, ITr) && Scaleform::GFx::AS3::Tracer::IsNumericType(this, ITr) )
      goto LABEL_48;
    goto LABEL_63;
  }
  for ( i = ITr; i; i = (Scaleform::GFx::AS3::InstanceTraits::Traits *)i->pParent.pObject )
    i->Flags |= 0x80u;
  v15 = (Scaleform::GFx::AS3::ClassTraits::Traits *)ValueTraits;
  if ( ValueTraits )
  {
    while ( (v15->Flags & 0x80) == 0 )
    {
      v15 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v15->pParent.pObject;
      if ( !v15 )
        goto LABEL_45;
    }
    froma = 1;
    if ( (v15->Flags & 0x20) != 0 )
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v5, v7, v15);
    else
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
        this,
        v5,
        v7,
        (Scaleform::GFx::AS3::InstanceTraits::Traits *)v15);
  }
LABEL_45:
  for ( j = ITr; j; j = (Scaleform::GFx::AS3::InstanceTraits::Traits *)j->pParent.pObject )
    j->Flags &= ~0x80u;
  if ( froma )
  {
LABEL_63:
    v3 = v75;
    goto LABEL_64;
  }
LABEL_48:
  v17 = this->CF->pFile->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v86, eCannotMergeTypesError, v17);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v17,
    v18,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pNode = v86.Message.pNode;
  --v86.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_50:
  v20 = 0;
  v21 = &to_st->ScopeStack.Data;
  v76 = 0;
  if ( !from_st->ScopeStack.Data.Size )
    goto LABEL_113;
  v22 = 0;
  v73 = 0;
  while ( 2 )
  {
    if ( v20 >= v21->Size )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        v21,
        (Scaleform::GFx::AS3::Value *)((char *)from_st->ScopeStack.Data.Data + v22));
      goto LABEL_128;
    }
    v23 = (Scaleform::GFx::AS3::Value *)((char *)v21->Data + v22);
    v24 = v23->Flags & 0x1F;
    v25 = (Scaleform::GFx::AS3::Value *)((char *)from_st->ScopeStack.Data.Data + v22);
    v82 = v24;
    if ( !v24 )
    {
      v26 = this->CF->pFile->VMRef->TraitsVoid.pObject;
      goto LABEL_71;
    }
    if ( (unsigned int)(v24 - 8) < 2 )
    {
      v26 = v23->value.VS._1.ITr;
LABEL_71:
      tra = v26;
      goto LABEL_72;
    }
    v26 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                           this->CF->pFile->VMRef,
                                                           v23);
    tra = v26;
LABEL_72:
    if ( v26 )
    {
      v27 = this->CF->pFile->VMRef;
      if ( v26 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v27->TraitsClassClass.pObject )
      {
        v26 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v27->TraitsObject.pObject;
        tra = v26;
      }
    }
    v28 = v25->Flags & 0x1F;
    v79 = v28;
    if ( v28 )
    {
      if ( (unsigned int)(v28 - 8) < 2 )
        v29 = v25->value.VS._1.ITr;
      else
        v29 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                               this->CF->pFile->VMRef,
                                                               v25);
    }
    else
    {
      v29 = this->CF->pFile->VMRef->TraitsVoid.pObject;
    }
    if ( v29 )
    {
      v30 = this->CF->pFile->VMRef;
      if ( v29 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v30->TraitsClassClass.pObject )
        v29 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v30->TraitsObject.pObject;
    }
    fromb = 0;
    if ( (((unsigned __int8)BYTE1(v23->Flags) ^ (unsigned __int8)BYTE1(v25->Flags)) & 1) != 0 )
      break;
    if ( v26 == v29 )
      goto LABEL_127;
    if ( !v82 )
    {
LABEL_126:
      Scaleform::GFx::AS3::Value::Assign(v23, v25);
      goto LABEL_127;
    }
    v31 = this->CF->pFile->VMRef;
    result_typea = v31->TraitsObject.pObject->ITraits.pObject;
    if ( tra == result_typea || tra == v31->TraitsClassClass.pObject->ITraits.pObject )
      goto LABEL_127;
    if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, v29) )
    {
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v23, v25, result_typea);
      goto LABEL_127;
    }
    if ( Scaleform::GFx::AS3::Tracer::IsNumericType(this, tra) && Scaleform::GFx::AS3::Tracer::IsNumericType(this, v29) )
    {
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v23, v25, v31->TraitsNumber.pObject->ITraits.pObject);
      goto LABEL_127;
    }
    if ( (unsigned int)(v82 - 12) <= 3 && !v23->value.VS._1.VInt
      || (v32 = v31->TraitsNull.pObject, v33 = tra, tra == v32) )
    {
      if ( (unsigned int)(v79 - 12) <= 3 && !v25->value.VS._1.VInt || v29 == v31->TraitsNull.pObject )
        goto LABEL_127;
      if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, v29)
        && Scaleform::GFx::AS3::Tracer::IsNumericType(this, v29) )
      {
        break;
      }
      goto LABEL_126;
    }
    if ( (unsigned int)(v79 - 12) <= 3 && !v25->value.VS._1.VInt || v29 == v32 )
    {
      if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, tra)
        && Scaleform::GFx::AS3::Tracer::IsNumericType(this, tra) )
      {
        break;
      }
      goto LABEL_127;
    }
    if ( tra )
    {
      do
      {
        v33->Flags |= 0x80u;
        v33 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v33->pParent.pObject;
      }
      while ( v33 );
    }
    v34 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v29;
    if ( v29 )
    {
      while ( (v34->Flags & 0x80) == 0 )
      {
        v34 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v34->pParent.pObject;
        if ( !v34 )
          goto LABEL_108;
      }
      fromb = 1;
      if ( (v34->Flags & 0x20) != 0 )
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v23, v25, v34);
      else
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
          this,
          v23,
          v25,
          (Scaleform::GFx::AS3::InstanceTraits::Traits *)v34);
    }
LABEL_108:
    for ( k = tra; k; k = (Scaleform::GFx::AS3::InstanceTraits::Traits *)k->pParent.pObject )
      k->Flags &= ~0x80u;
    if ( fromb )
    {
LABEL_127:
      v22 = v73;
      v21 = &to_st->ScopeStack.Data;
      v20 = v76;
LABEL_128:
      ++v20;
      v22 += 16;
      v76 = v20;
      v73 = v22;
      if ( v20 >= from_st->ScopeStack.Data.Size )
        goto LABEL_113;
      continue;
    }
    break;
  }
  v36 = this->CF->pFile->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v86, eCannotMergeTypesError, v36);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v36,
    v37,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v38 = v86.Message.pNode;
  --v86.Message.pNode->RefCount;
  if ( !v38->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
LABEL_113:
  v39 = from_st;
  Size = from_st->Registers.Data.Size;
  if ( to_st->Registers.Data.Size == Size )
  {
    v41 = 0;
    v77 = 0;
    if ( Size )
    {
      v42 = 0;
      v74 = 0;
      while ( 1 )
      {
        v43 = &to_st->Registers.Data;
        if ( v41 < to_st->Registers.Data.Size )
          break;
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          v43,
          (Scaleform::GFx::AS3::Value *)((char *)v39->Registers.Data.Data + v42));
LABEL_195:
        v41 = v77 + 1;
        v42 += 16;
        v77 = v41;
        v74 = v42;
        if ( v41 >= v39->Registers.Data.Size )
        {
          *((_DWORD *)to + 2) |= 1u;
          return;
        }
      }
      v44 = (Scaleform::GFx::AS3::Value *)((char *)v43->Data + v42);
      v45 = v44->Flags & 0x1F;
      v46 = (Scaleform::GFx::AS3::Value *)((char *)v39->Registers.Data.Data + v42);
      v83 = v45;
      if ( v45 )
      {
        if ( (unsigned int)(v45 - 8) >= 2 )
        {
          v47 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                 this->CF->pFile->VMRef,
                                                                 v44);
          trb = v47;
          goto LABEL_136;
        }
        v47 = v44->value.VS._1.ITr;
      }
      else
      {
        v47 = this->CF->pFile->VMRef->TraitsVoid.pObject;
      }
      trb = v47;
LABEL_136:
      if ( v47 )
      {
        v48 = this->CF->pFile->VMRef;
        if ( v47 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v48->TraitsClassClass.pObject )
        {
          v47 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v48->TraitsObject.pObject;
          trb = v47;
        }
      }
      v49 = v46->Flags & 0x1F;
      v80 = v49;
      if ( v49 )
      {
        if ( (unsigned int)(v49 - 8) < 2 )
          v50 = v46->value.VS._1.ITr;
        else
          v50 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                 this->CF->pFile->VMRef,
                                                                 v46);
      }
      else
      {
        v50 = this->CF->pFile->VMRef->TraitsVoid.pObject;
      }
      if ( v50 )
      {
        v51 = this->CF->pFile->VMRef;
        if ( v50 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v51->TraitsClassClass.pObject )
          v50 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v51->TraitsObject.pObject;
      }
      v52 = 1 << (v77 & 7);
      v85 = v77 & 7;
      pData = from_st->RegistersAlive.pData;
      fromc = 0;
      v86.ID = v77 >> 3;
      v84 = v52;
      if ( ((unsigned __int8)v52 & pData[v77 >> 3]) == 0 )
        goto LABEL_188;
      if ( ((unsigned __int8)v52 & to_st->RegistersAlive.pData[v77 >> 3]) != 0 )
      {
        if ( v47 == v50 )
          goto LABEL_188;
        if ( v83 )
        {
          v54 = this->CF->pFile->VMRef;
          result_typeb = v54->TraitsObject.pObject->ITraits.pObject;
          if ( trb == result_typeb || trb == v54->TraitsClassClass.pObject->ITraits.pObject )
            goto LABEL_188;
          if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, v50) )
          {
            Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v44, v46, result_typeb);
            goto LABEL_188;
          }
          if ( Scaleform::GFx::AS3::Tracer::IsNumericType(this, trb)
            && Scaleform::GFx::AS3::Tracer::IsNumericType(this, v50) )
          {
            Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
              this,
              v44,
              v46,
              v54->TraitsNumber.pObject->ITraits.pObject);
            goto LABEL_188;
          }
          if ( (unsigned int)(v83 - 12) > 3 || v44->value.VS._1.VInt )
          {
            v55 = v54->TraitsNull.pObject;
            v56 = trb;
            if ( trb != v55 )
            {
              if ( (unsigned int)(v80 - 12) <= 3 && !v46->value.VS._1.VInt || v50 == v55 )
              {
                if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, trb)
                  && Scaleform::GFx::AS3::Tracer::IsNumericType(this, trb) )
                {
                  goto LABEL_176;
                }
              }
              else
              {
                if ( trb )
                {
                  do
                  {
                    v56->Flags |= 0x80u;
                    v56 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v56->pParent.pObject;
                  }
                  while ( v56 );
                }
                v57 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v50;
                if ( v50 )
                {
                  while ( (v57->Flags & 0x80) == 0 )
                  {
                    v57 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v57->pParent.pObject;
                    if ( !v57 )
                      goto LABEL_173;
                  }
                  fromc = 1;
                  if ( (v57->Flags & 0x20) != 0 )
                    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v44, v46, v57);
                  else
                    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
                      this,
                      v44,
                      v46,
                      (Scaleform::GFx::AS3::InstanceTraits::Traits *)v57);
                }
LABEL_173:
                for ( m = trb; m; m = (Scaleform::GFx::AS3::InstanceTraits::Traits *)m->pParent.pObject )
                  m->Flags &= ~0x80u;
                if ( !fromc )
                {
LABEL_176:
                  v59 = this->CF->pFile->VMRef;
                  Scaleform::GFx::AS3::VM::Error::Error(&v86, eCannotMergeTypesError, v59);
                  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
                    v59,
                    v60,
                    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
                  v61 = v86.Message.pNode;
                  --v86.Message.pNode->RefCount;
                  if ( !v61->RefCount )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v61);
                  goto LABEL_178;
                }
              }
              goto LABEL_188;
            }
          }
          if ( (unsigned int)(v80 - 12) <= 3 && !v46->value.VS._1.VInt || v50 == v54->TraitsNull.pObject )
          {
LABEL_188:
            v62 = (v84 & from_st->RegistersAlive.pData[v86.ID]) != 0 || (v84 & to_st->RegistersAlive.pData[v86.ID]) != 0;
            v42 = v74;
            v39 = from_st;
            if ( v62 )
              to_st->RegistersAlive.pData[v86.ID] |= 1 << v85;
            else
              to_st->RegistersAlive.pData[v86.ID] &= ~(1 << v85);
            goto LABEL_195;
          }
          if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, v50)
            && Scaleform::GFx::AS3::Tracer::IsNumericType(this, v50) )
          {
            goto LABEL_176;
          }
        }
      }
      Scaleform::GFx::AS3::Value::Assign(v44, v46);
      goto LABEL_188;
    }
  }
LABEL_178:
  *((_DWORD *)to + 2) |= 1u;
}
