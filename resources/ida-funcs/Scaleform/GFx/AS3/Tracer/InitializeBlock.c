void __thiscall Scaleform::GFx::AS3::Tracer::InitializeBlock(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::Block *to,
        const Scaleform::GFx::AS3::TR::Block *from)
{
  Scaleform::GFx::AS3::TR::State *State; // ebx
  unsigned int v4; // esi
  int v5; // ebp
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // ecx
  Scaleform::GFx::AS3::Value *v7; // edi
  const Scaleform::GFx::AS3::Value *v8; // esi
  int v9; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ebx
  Scaleform::GFx::AS3::VM *VMRef; // eax
  int v12; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // eax
  Scaleform::GFx::AS3::VM *v14; // ecx
  Scaleform::GFx::AS3::VM *v15; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v16; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v17; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v18; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *i; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v20; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *j; // eax
  const Scaleform::GFx::AS3::Traits *v22; // ebp
  unsigned int v23; // esi
  int v24; // ebp
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v25; // ecx
  Scaleform::GFx::AS3::Value *v26; // edi
  const Scaleform::GFx::AS3::Value *v27; // esi
  int v28; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v29; // eax
  Scaleform::GFx::AS3::VM *v30; // eax
  unsigned int Flags; // ebx
  int v32; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::VM *v34; // ecx
  Scaleform::GFx::AS3::VM *v35; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v36; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v37; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v38; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v39; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *k; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v41; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *m; // eax
  unsigned int Size; // eax
  int v44; // ebp
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v45; // ecx
  Scaleform::GFx::AS3::Value *v46; // edi
  int v47; // eax
  const Scaleform::GFx::AS3::Value *v48; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v49; // eax
  Scaleform::GFx::AS3::VM *v50; // ecx
  int v51; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v52; // ebp
  Scaleform::GFx::AS3::VM *v53; // eax
  int v54; // eax
  Scaleform::GFx::AS3::VM *v55; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v56; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v57; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v58; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *n; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v60; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *ii; // eax
  const Scaleform::GFx::AS3::Traits *v62; // ebp
  bool v63; // cl
  unsigned __int8 *pData; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *to_tr; // [esp+14h] [ebp-2Ch]
  Scaleform::GFx::AS3::InstanceTraits::Traits *to_tra; // [esp+14h] [ebp-2Ch]
  Scaleform::GFx::AS3::InstanceTraits::Traits *to_trb; // [esp+14h] [ebp-2Ch]
  Scaleform::GFx::AS3::InstanceTraits::Traits *tr; // [esp+18h] [ebp-28h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *tra; // [esp+18h] [ebp-28h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *trb; // [esp+18h] [ebp-28h]
  Scaleform::GFx::AS3::TR::State *to_st; // [esp+1Ch] [ebp-24h]
  const Scaleform::GFx::AS3::TR::State *from_st; // [esp+20h] [ebp-20h]
  unsigned int v74; // [esp+24h] [ebp-1Ch]
  int v75; // [esp+24h] [ebp-1Ch]
  unsigned int v76; // [esp+24h] [ebp-1Ch]
  int v77; // [esp+28h] [ebp-18h]
  unsigned int v78; // [esp+28h] [ebp-18h]
  int v79; // [esp+28h] [ebp-18h]
  int v80; // [esp+2Ch] [ebp-14h]
  int v81; // [esp+2Ch] [ebp-14h]
  int v82; // [esp+2Ch] [ebp-14h]
  int v83; // [esp+30h] [ebp-10h]
  int v84; // [esp+34h] [ebp-Ch]
  int v85; // [esp+34h] [ebp-Ch]
  char v86; // [esp+34h] [ebp-Ch]
  unsigned int v87; // [esp+38h] [ebp-8h]
  unsigned __int8 v88; // [esp+3Ch] [ebp-4h]
  char froma; // [esp+48h] [ebp+8h]
  char fromb; // [esp+48h] [ebp+8h]
  char fromc; // [esp+48h] [ebp+8h]

  State = from->State;
  v4 = 0;
  from_st = State;
  to_st = to->State;
  v74 = 0;
  if ( !State->OpStack.Data.Size )
    goto LABEL_53;
  v5 = 0;
  v80 = 0;
  while ( 1 )
  {
    p_Data = &to_st->OpStack.Data;
    if ( v4 < to_st->OpStack.Data.Size )
      break;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      p_Data,
      (Scaleform::GFx::AS3::Value *)((char *)State->OpStack.Data.Data + v5));
LABEL_67:
    ++v4;
    v5 += 16;
    v74 = v4;
    v80 = v5;
    if ( v4 >= State->OpStack.Data.Size )
      goto LABEL_53;
  }
  v7 = (Scaleform::GFx::AS3::Value *)((char *)p_Data->Data + v5);
  v8 = (Scaleform::GFx::AS3::Value *)((char *)State->OpStack.Data.Data + v5);
  v9 = v7->Flags & 0x1F;
  v84 = v9;
  if ( !v9 )
  {
    pObject = this->CF->pFile->VMRef->TraitsVoid.pObject;
    goto LABEL_11;
  }
  if ( v9 == 8 || v9 == 9 )
  {
    pObject = v7->value.VS._1.ITr;
LABEL_11:
    to_tr = pObject;
    goto LABEL_12;
  }
  pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v7);
  to_tr = pObject;
LABEL_12:
  if ( pObject )
  {
    VMRef = this->CF->pFile->VMRef;
    if ( pObject == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
    {
      pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
      to_tr = pObject;
    }
  }
  v12 = v8->Flags & 0x1F;
  v77 = v12;
  if ( v12 )
  {
    if ( (unsigned int)(v12 - 8) < 2 )
      ITr = v8->value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v8);
  }
  else
  {
    ITr = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  tr = ITr;
  if ( ITr )
  {
    v14 = this->CF->pFile->VMRef;
    if ( ITr == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v14->TraitsClassClass.pObject )
    {
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v14->TraitsObject.pObject;
      tr = ITr;
    }
  }
  froma = 0;
  if ( pObject == ITr )
    goto LABEL_66;
  if ( !v9 )
  {
LABEL_65:
    Scaleform::GFx::AS3::Value::Assign(v7, v8);
    goto LABEL_66;
  }
  v15 = this->CF->pFile->VMRef;
  v16 = v15->TraitsObject.pObject->ITraits.pObject;
  if ( to_tr == v16 || to_tr == v15->TraitsClassClass.pObject->ITraits.pObject )
    goto LABEL_66;
  if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, tr) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v7, v8, v16);
    goto LABEL_66;
  }
  if ( Scaleform::GFx::AS3::Tracer::IsNumericType(this, to_tr) && Scaleform::GFx::AS3::Tracer::IsNumericType(this, tr) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v7, v8, v15->TraitsNumber.pObject->ITraits.pObject);
    goto LABEL_66;
  }
  if ( (unsigned int)(v84 - 12) <= 3 && !v7->value.VS._1.VInt
    || (v17 = v15->TraitsNull.pObject, v18 = to_tr, to_tr == v17) )
  {
    if ( (unsigned int)(v77 - 12) <= 3 && !v8->value.VS._1.VInt || tr == v15->TraitsNull.pObject )
      goto LABEL_66;
    v22 = tr;
    if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, tr) && Scaleform::GFx::AS3::Tracer::IsNumericType(this, tr) )
      goto LABEL_52;
    goto LABEL_65;
  }
  if ( (unsigned int)(v77 - 12) <= 3 && !v8->value.VS._1.VInt || tr == v17 )
  {
    if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, to_tr)
      && Scaleform::GFx::AS3::Tracer::IsNumericType(this, to_tr) )
    {
      goto LABEL_51;
    }
    goto LABEL_66;
  }
  for ( i = to_tr; i; i = (Scaleform::GFx::AS3::InstanceTraits::Traits *)i->pParent.pObject )
    i->Flags |= 0x80u;
  v20 = (Scaleform::GFx::AS3::ClassTraits::Traits *)tr;
  if ( tr )
  {
    while ( (v20->Flags & 0x80) == 0 )
    {
      v20 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v20->pParent.pObject;
      if ( !v20 )
        goto LABEL_48;
    }
    froma = 1;
    if ( (v20->Flags & 0x20) != 0 )
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v7, v8, v20);
    else
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
        this,
        v7,
        v8,
        (Scaleform::GFx::AS3::InstanceTraits::Traits *)v20);
    v18 = to_tr;
  }
LABEL_48:
  for ( j = v18; j; j = (Scaleform::GFx::AS3::InstanceTraits::Traits *)j->pParent.pObject )
    j->Flags &= ~0x80u;
  if ( froma )
  {
LABEL_66:
    v5 = v80;
    State = (Scaleform::GFx::AS3::TR::State *)from_st;
    v4 = v74;
    goto LABEL_67;
  }
LABEL_51:
  v22 = tr;
LABEL_52:
  Scaleform::GFx::AS3::Tracer::ThrowMergeTypeError(this, to_tr, v22);
  State = (Scaleform::GFx::AS3::TR::State *)from_st;
LABEL_53:
  v23 = 0;
  v78 = 0;
  if ( State->ScopeStack.Data.Size )
  {
    v24 = 0;
    v75 = 0;
    while ( 1 )
    {
      v25 = &to_st->ScopeStack.Data;
      if ( v23 < to_st->ScopeStack.Data.Size )
        break;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        v25,
        (Scaleform::GFx::AS3::Value *)((char *)State->ScopeStack.Data.Data + v24));
LABEL_134:
      ++v23;
      v24 += 16;
      v78 = v23;
      v75 = v24;
      if ( v23 >= State->ScopeStack.Data.Size )
        goto LABEL_118;
    }
    v26 = (Scaleform::GFx::AS3::Value *)((char *)v25->Data + v24);
    v27 = (Scaleform::GFx::AS3::Value *)((char *)State->ScopeStack.Data.Data + v24);
    v28 = v26->Flags & 0x1F;
    v85 = v28;
    if ( v28 )
    {
      if ( v28 == 8 )
      {
        to_tra = v26->value.VS._1.ITr;
LABEL_77:
        if ( to_tra )
        {
          v30 = this->CF->pFile->VMRef;
          if ( to_tra == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v30->TraitsClassClass.pObject )
            to_tra = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v30->TraitsObject.pObject;
        }
        Flags = v27->Flags;
        v32 = v27->Flags & 0x1F;
        v81 = v32;
        if ( v32 )
        {
          if ( (unsigned int)(v32 - 8) < 2 )
            ValueTraits = v27->value.VS._1.ITr;
          else
            ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                           this->CF->pFile->VMRef,
                                                                           v27);
        }
        else
        {
          ValueTraits = this->CF->pFile->VMRef->TraitsVoid.pObject;
        }
        tra = ValueTraits;
        if ( ValueTraits )
        {
          v34 = this->CF->pFile->VMRef;
          if ( ValueTraits == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v34->TraitsClassClass.pObject )
          {
            ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v34->TraitsObject.pObject;
            tra = ValueTraits;
          }
        }
        fromb = 0;
        if ( (((unsigned __int8)BYTE1(v26->Flags) ^ BYTE1(Flags)) & 1) != 0 )
          goto LABEL_117;
        if ( to_tra == ValueTraits )
          goto LABEL_133;
        if ( v28 )
        {
          v35 = this->CF->pFile->VMRef;
          v36 = v35->TraitsObject.pObject->ITraits.pObject;
          if ( to_tra == v36 || to_tra == v35->TraitsClassClass.pObject->ITraits.pObject )
            goto LABEL_133;
          if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, tra) )
          {
            Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v26, v27, v36);
LABEL_133:
            State = (Scaleform::GFx::AS3::TR::State *)from_st;
            v24 = v75;
            v23 = v78;
            goto LABEL_134;
          }
          v37 = tra;
          if ( Scaleform::GFx::AS3::Tracer::IsNumericType(this, to_tra)
            && Scaleform::GFx::AS3::Tracer::IsNumericType(this, tra) )
          {
            Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
              this,
              v26,
              v27,
              v35->TraitsNumber.pObject->ITraits.pObject);
            goto LABEL_133;
          }
          if ( (unsigned int)(v85 - 12) > 3 || v26->value.VS._1.VInt )
          {
            v38 = v35->TraitsNull.pObject;
            v39 = to_tra;
            if ( to_tra != v38 )
            {
              if ( (unsigned int)(v81 - 12) <= 3 && !v27->value.VS._1.VInt || tra == v38 )
              {
                if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, to_tra)
                  && Scaleform::GFx::AS3::Tracer::IsNumericType(this, to_tra) )
                {
                  goto LABEL_117;
                }
              }
              else
              {
                for ( k = to_tra; k; k = (Scaleform::GFx::AS3::InstanceTraits::Traits *)k->pParent.pObject )
                  k->Flags |= 0x80u;
                v41 = (Scaleform::GFx::AS3::ClassTraits::Traits *)tra;
                if ( tra )
                {
                  while ( (v41->Flags & 0x80) == 0 )
                  {
                    v41 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v41->pParent.pObject;
                    if ( !v41 )
                      goto LABEL_114;
                  }
                  fromb = 1;
                  if ( (v41->Flags & 0x20) != 0 )
                    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v26, v27, v41);
                  else
                    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
                      this,
                      v26,
                      v27,
                      (Scaleform::GFx::AS3::InstanceTraits::Traits *)v41);
                  v39 = to_tra;
                }
LABEL_114:
                for ( m = v39; m; m = (Scaleform::GFx::AS3::InstanceTraits::Traits *)m->pParent.pObject )
                  m->Flags &= ~0x80u;
                if ( !fromb )
                {
LABEL_117:
                  Scaleform::GFx::AS3::Tracer::ThrowMergeTypeError(this, to_tra, tra);
                  State = (Scaleform::GFx::AS3::TR::State *)from_st;
                  goto LABEL_118;
                }
              }
              goto LABEL_133;
            }
          }
          if ( (unsigned int)(v81 - 12) <= 3 )
          {
            if ( !v27->value.VS._1.VInt )
              goto LABEL_133;
            v37 = tra;
          }
          if ( v37 == v35->TraitsNull.pObject )
            goto LABEL_133;
          if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, tra)
            && Scaleform::GFx::AS3::Tracer::IsNumericType(this, tra) )
          {
            goto LABEL_117;
          }
        }
        Scaleform::GFx::AS3::Value::Assign(v26, v27);
        goto LABEL_133;
      }
      if ( v28 == 9 )
        v29 = v26->value.VS._1.ITr;
      else
        v29 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                               this->CF->pFile->VMRef,
                                                               v26);
    }
    else
    {
      v29 = this->CF->pFile->VMRef->TraitsVoid.pObject;
    }
    to_tra = v29;
    goto LABEL_77;
  }
LABEL_118:
  Size = State->Registers.Data.Size;
  if ( to_st->Registers.Data.Size != Size || (v76 = 0, !Size) )
  {
LABEL_186:
    *((_DWORD *)to + 2) |= 1u;
    return;
  }
  v44 = 0;
  v79 = 0;
  do
  {
    v45 = &to_st->Registers.Data;
    if ( v76 >= to_st->Registers.Data.Size )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        v45,
        (Scaleform::GFx::AS3::Value *)((char *)State->Registers.Data.Data + v44));
      goto LABEL_203;
    }
    v46 = (Scaleform::GFx::AS3::Value *)((char *)v45->Data + v44);
    v47 = v46->Flags & 0x1F;
    v48 = (Scaleform::GFx::AS3::Value *)((char *)State->Registers.Data.Data + v44);
    v82 = v47;
    if ( !v47 )
    {
      v49 = this->CF->pFile->VMRef->TraitsVoid.pObject;
      goto LABEL_141;
    }
    if ( (unsigned int)(v47 - 8) < 2 )
    {
      v49 = v46->value.VS._1.ITr;
LABEL_141:
      to_trb = v49;
      goto LABEL_142;
    }
    v49 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                           this->CF->pFile->VMRef,
                                                           v46);
    to_trb = v49;
LABEL_142:
    if ( v49 )
    {
      v50 = this->CF->pFile->VMRef;
      if ( v49 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v50->TraitsClassClass.pObject )
        to_trb = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v50->TraitsObject.pObject;
    }
    v51 = v48->Flags & 0x1F;
    v83 = v51;
    if ( v51 )
    {
      if ( (unsigned int)(v51 - 8) >= 2 )
      {
        v52 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                               this->CF->pFile->VMRef,
                                                               v48);
        trb = v52;
        goto LABEL_151;
      }
      v52 = v48->value.VS._1.ITr;
    }
    else
    {
      v52 = this->CF->pFile->VMRef->TraitsVoid.pObject;
    }
    trb = v52;
LABEL_151:
    if ( v52 )
    {
      v53 = this->CF->pFile->VMRef;
      if ( v52 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v53->TraitsClassClass.pObject )
      {
        v52 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v53->TraitsObject.pObject;
        trb = v52;
      }
    }
    v54 = 1 << (v76 & 7);
    v86 = v76 & 7;
    fromc = 0;
    v87 = v76 >> 3;
    v88 = v54;
    if ( ((unsigned __int8)v54 & State->RegistersAlive.pData[v76 >> 3]) == 0 )
      goto LABEL_196;
    if ( ((unsigned __int8)v54 & to_st->RegistersAlive.pData[v76 >> 3]) == 0 )
      goto LABEL_195;
    if ( to_trb == v52 )
      goto LABEL_196;
    if ( !v82 )
      goto LABEL_195;
    v55 = this->CF->pFile->VMRef;
    v56 = v55->TraitsObject.pObject->ITraits.pObject;
    if ( to_trb == v56 || to_trb == v55->TraitsClassClass.pObject->ITraits.pObject )
      goto LABEL_196;
    if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, trb) )
    {
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v46, v48, v56);
      goto LABEL_196;
    }
    if ( Scaleform::GFx::AS3::Tracer::IsNumericType(this, to_trb)
      && Scaleform::GFx::AS3::Tracer::IsNumericType(this, trb) )
    {
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v46, v48, v55->TraitsNumber.pObject->ITraits.pObject);
      goto LABEL_196;
    }
    if ( (unsigned int)(v82 - 12) > 3 || v46->value.VS._1.VInt )
    {
      v57 = v55->TraitsNull.pObject;
      v58 = to_trb;
      if ( to_trb != v57 )
      {
        if ( (unsigned int)(v83 - 12) <= 3 && !v48->value.VS._1.VInt || trb == v57 )
        {
          if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, to_trb)
            && Scaleform::GFx::AS3::Tracer::IsNumericType(this, to_trb) )
          {
            goto LABEL_184;
          }
        }
        else
        {
          for ( n = to_trb; n; n = (Scaleform::GFx::AS3::InstanceTraits::Traits *)n->pParent.pObject )
            n->Flags |= 0x80u;
          v60 = (Scaleform::GFx::AS3::ClassTraits::Traits *)trb;
          if ( trb )
          {
            while ( (v60->Flags & 0x80) == 0 )
            {
              v60 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v60->pParent.pObject;
              if ( !v60 )
                goto LABEL_181;
            }
            fromc = 1;
            if ( (v60->Flags & 0x20) != 0 )
              Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v46, v48, v60);
            else
              Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
                this,
                v46,
                v48,
                (Scaleform::GFx::AS3::InstanceTraits::Traits *)v60);
            v58 = to_trb;
          }
LABEL_181:
          for ( ii = v58; ii; ii = (Scaleform::GFx::AS3::InstanceTraits::Traits *)ii->pParent.pObject )
            ii->Flags &= ~0x80u;
          if ( !fromc )
          {
LABEL_184:
            v62 = trb;
LABEL_185:
            Scaleform::GFx::AS3::Tracer::ThrowMergeTypeError(this, to_trb, v62);
            goto LABEL_186;
          }
        }
        goto LABEL_196;
      }
    }
    if ( ((unsigned int)(v83 - 12) > 3 || v48->value.VS._1.VInt) && trb != v55->TraitsNull.pObject )
    {
      v62 = trb;
      if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, trb)
        && Scaleform::GFx::AS3::Tracer::IsNumericType(this, trb) )
      {
        goto LABEL_185;
      }
LABEL_195:
      Scaleform::GFx::AS3::Value::Assign(v46, v48);
    }
LABEL_196:
    State = (Scaleform::GFx::AS3::TR::State *)from_st;
    v63 = (v88 & from_st->RegistersAlive.pData[v87]) != 0 || (v88 & to_st->RegistersAlive.pData[v87]) != 0;
    v44 = v79;
    pData = to_st->RegistersAlive.pData;
    if ( v63 )
      pData[v87] |= 1 << v86;
    else
      pData[v87] &= ~(1 << v86);
LABEL_203:
    v44 += 16;
    ++v76;
    v79 = v44;
  }
  while ( v76 < State->Registers.Data.Size );
  *((_DWORD *)to + 2) |= 1u;
}
