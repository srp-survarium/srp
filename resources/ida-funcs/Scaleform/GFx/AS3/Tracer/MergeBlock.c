Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Tracer::MergeBlock(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::TR::Block *to,
        const Scaleform::GFx::AS3::TR::Block *from)
{
  Scaleform::GFx::AS3::TR::State *State; // ebp
  Scaleform::GFx::AS3::TR::State *v5; // ecx
  unsigned int Size; // eax
  unsigned int v7; // esi
  int v8; // ebx
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // ecx
  Scaleform::GFx::AS3::Value *Data; // esi
  Scaleform::GFx::AS3::Value *v11; // edi
  int v12; // ebp
  const Scaleform::GFx::AS3::Value *v13; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ebx
  Scaleform::GFx::AS3::VM *VMRef; // eax
  int v16; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // eax
  Scaleform::GFx::AS3::VM *v18; // ecx
  Scaleform::GFx::AS3::VM *v19; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v20; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v21; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v22; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *i; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v24; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *j; // eax
  const Scaleform::GFx::AS3::Traits *v26; // ebx
  unsigned int v27; // esi
  int v28; // ebx
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v29; // ecx
  Scaleform::GFx::AS3::Value *v30; // esi
  Scaleform::GFx::AS3::Value *v31; // edi
  int v32; // ebp
  const Scaleform::GFx::AS3::Value *v33; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::VM *v35; // eax
  unsigned int Flags; // ebx
  int v37; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v38; // eax
  Scaleform::GFx::AS3::VM *v39; // ecx
  Scaleform::GFx::AS3::VM *v40; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v41; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v42; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v43; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *k; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v45; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *m; // eax
  Scaleform::GFx::AS3::VM *v47; // esi
  const Scaleform::GFx::AS3::VM::Error *v48; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // edx
  int v53; // ebx
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v54; // ecx
  Scaleform::GFx::AS3::Value *v55; // edi
  int v56; // eax
  const Scaleform::GFx::AS3::Value *v57; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v58; // ebx
  Scaleform::GFx::AS3::VM *v59; // eax
  int v60; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v61; // ebp
  Scaleform::GFx::AS3::VM *v62; // eax
  Scaleform::GFx::AS3::VM::ErrorID v63; // eax
  unsigned __int8 *pData; // ecx
  Scaleform::GFx::AS3::VM *v65; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v66; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v67; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v68; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *n; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v70; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *ii; // eax
  const Scaleform::GFx::AS3::Traits *v72; // ebp
  bool v73; // cl
  unsigned __int8 *v74; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *tr; // [esp+14h] [ebp-30h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *tra; // [esp+14h] [ebp-30h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *trb; // [esp+14h] [ebp-30h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *to_tr; // [esp+18h] [ebp-2Ch]
  Scaleform::GFx::AS3::InstanceTraits::Traits *to_tra; // [esp+18h] [ebp-2Ch]
  Scaleform::GFx::AS3::InstanceTraits::Traits *to_trb; // [esp+18h] [ebp-2Ch]
  Scaleform::GFx::AS3::TR::State *to_st; // [esp+1Ch] [ebp-28h]
  const Scaleform::GFx::AS3::TR::State *from_st; // [esp+20h] [ebp-24h]
  unsigned int v84; // [esp+24h] [ebp-20h]
  int v85; // [esp+24h] [ebp-20h]
  unsigned int v86; // [esp+24h] [ebp-20h]
  int v87; // [esp+28h] [ebp-1Ch]
  unsigned int v88; // [esp+28h] [ebp-1Ch]
  int v89; // [esp+28h] [ebp-1Ch]
  int v90; // [esp+2Ch] [ebp-18h]
  int v91; // [esp+2Ch] [ebp-18h]
  int v92; // [esp+2Ch] [ebp-18h]
  int v93; // [esp+30h] [ebp-14h]
  int v94; // [esp+34h] [ebp-10h]
  int v95; // [esp+34h] [ebp-10h]
  char v96; // [esp+34h] [ebp-10h]
  unsigned int v97; // [esp+38h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v98; // [esp+3Ch] [ebp-8h] BYREF
  bool toa; // [esp+4Ch] [ebp+8h]
  bool tob; // [esp+4Ch] [ebp+8h]
  bool toc; // [esp+4Ch] [ebp+8h]
  char froma; // [esp+50h] [ebp+Ch]
  char fromb; // [esp+50h] [ebp+Ch]
  char fromc; // [esp+50h] [ebp+Ch]

  State = from->State;
  v5 = to->State;
  from_st = State;
  to_st = v5;
  if ( (to->Type & 4) != 0 )
    goto LABEL_134;
  Size = State->OpStack.Data.Size;
  if ( v5->OpStack.Data.Size != Size )
    goto LABEL_55;
  v7 = 0;
  v84 = 0;
  if ( !Size )
    goto LABEL_55;
  v8 = 0;
  v90 = 0;
  while ( 1 )
  {
    p_Data = &v5->OpStack.Data;
    if ( v7 >= p_Data->Size )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        p_Data,
        (Scaleform::GFx::AS3::Value *)((char *)State->OpStack.Data.Data + v8));
      goto LABEL_69;
    }
    Data = State->OpStack.Data.Data;
    v11 = (Scaleform::GFx::AS3::Value *)((char *)p_Data->Data + v8);
    v12 = v11->Flags & 0x1F;
    v13 = (Scaleform::GFx::AS3::Value *)((char *)Data + v8);
    v94 = v12;
    if ( !v12 )
    {
      pObject = this->CF->pFile->VMRef->TraitsVoid.pObject;
      goto LABEL_13;
    }
    if ( v12 == 8 || v12 == 9 )
    {
      pObject = v11->value.VS._1.ITr;
LABEL_13:
      to_tr = pObject;
      goto LABEL_14;
    }
    pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                               this->CF->pFile->VMRef,
                                                               v11);
    to_tr = pObject;
LABEL_14:
    if ( pObject )
    {
      VMRef = this->CF->pFile->VMRef;
      if ( pObject == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
      {
        pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
        to_tr = pObject;
      }
    }
    v16 = v13->Flags & 0x1F;
    v87 = v16;
    if ( v16 )
    {
      if ( (unsigned int)(v16 - 8) < 2 )
        ITr = v13->value.VS._1.ITr;
      else
        ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                               this->CF->pFile->VMRef,
                                                               v13);
    }
    else
    {
      ITr = this->CF->pFile->VMRef->TraitsVoid.pObject;
    }
    tr = ITr;
    if ( ITr )
    {
      v18 = this->CF->pFile->VMRef;
      if ( ITr == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v18->TraitsClassClass.pObject )
      {
        ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v18->TraitsObject.pObject;
        tr = ITr;
      }
    }
    froma = 0;
    if ( pObject == ITr )
      goto LABEL_68;
    if ( !v12 )
      goto LABEL_67;
    v19 = this->CF->pFile->VMRef;
    v20 = v19->TraitsObject.pObject->ITraits.pObject;
    if ( to_tr == v20 || to_tr == v19->TraitsClassClass.pObject->ITraits.pObject )
      goto LABEL_68;
    if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, tr) )
    {
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v11, v13, v20);
      goto LABEL_68;
    }
    toa = Scaleform::GFx::AS3::Tracer::IsNumericType(this, to_tr);
    if ( toa && Scaleform::GFx::AS3::Tracer::IsNumericType(this, tr) )
    {
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v11, v13, v19->TraitsNumber.pObject->ITraits.pObject);
      goto LABEL_68;
    }
    if ( (unsigned int)(v94 - 12) <= 3 && !v11->value.VS._1.VInt
      || (v21 = v19->TraitsNull.pObject, v22 = to_tr, to_tr == v21) )
    {
      if ( (unsigned int)(v87 - 12) <= 3 && !v13->value.VS._1.VInt || tr == v19->TraitsNull.pObject )
        goto LABEL_68;
      v26 = tr;
      if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, tr) && Scaleform::GFx::AS3::Tracer::IsNumericType(this, tr) )
        goto LABEL_54;
LABEL_67:
      Scaleform::GFx::AS3::Value::Assign(v11, v13);
      goto LABEL_68;
    }
    if ( (unsigned int)(v87 - 12) <= 3 && !v13->value.VS._1.VInt || tr == v21 )
    {
      if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, to_tr) && toa )
        break;
      goto LABEL_68;
    }
    for ( i = to_tr; i; i = (Scaleform::GFx::AS3::InstanceTraits::Traits *)i->pParent.pObject )
      i->Flags |= 0x80u;
    v24 = (Scaleform::GFx::AS3::ClassTraits::Traits *)tr;
    if ( tr )
    {
      while ( (v24->Flags & 0x80) == 0 )
      {
        v24 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v24->pParent.pObject;
        if ( !v24 )
          goto LABEL_50;
      }
      froma = 1;
      if ( (v24->Flags & 0x20) != 0 )
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v11, v13, v24);
      else
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
          this,
          v11,
          v13,
          (Scaleform::GFx::AS3::InstanceTraits::Traits *)v24);
      v22 = to_tr;
    }
LABEL_50:
    for ( j = v22; j; j = (Scaleform::GFx::AS3::InstanceTraits::Traits *)j->pParent.pObject )
      j->Flags &= ~0x80u;
    if ( !froma )
      break;
LABEL_68:
    State = (Scaleform::GFx::AS3::TR::State *)from_st;
    v7 = v84;
    v8 = v90;
LABEL_69:
    ++v7;
    v8 += 16;
    v84 = v7;
    v90 = v8;
    if ( v7 >= State->OpStack.Data.Size )
      goto LABEL_55;
    v5 = to_st;
  }
  v26 = tr;
LABEL_54:
  Scaleform::GFx::AS3::Tracer::ThrowMergeTypeError(this, to_tr, v26);
  State = (Scaleform::GFx::AS3::TR::State *)from_st;
LABEL_55:
  v27 = 0;
  v88 = 0;
  if ( State->ScopeStack.Data.Size )
  {
    v28 = 0;
    v85 = 0;
    while ( 1 )
    {
      v29 = &to_st->ScopeStack.Data;
      if ( v27 < to_st->ScopeStack.Data.Size )
        break;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        v29,
        (Scaleform::GFx::AS3::Value *)((char *)State->ScopeStack.Data.Data + v28));
LABEL_132:
      ++v27;
      v28 += 16;
      v88 = v27;
      v85 = v28;
      if ( v27 >= State->ScopeStack.Data.Size )
        goto LABEL_133;
    }
    v30 = State->ScopeStack.Data.Data;
    v31 = (Scaleform::GFx::AS3::Value *)((char *)v29->Data + v28);
    v32 = v31->Flags & 0x1F;
    v33 = (Scaleform::GFx::AS3::Value *)((char *)v30 + v28);
    v95 = v32;
    if ( !v32 )
    {
      ValueTraits = this->CF->pFile->VMRef->TraitsVoid.pObject;
      goto LABEL_78;
    }
    if ( v32 == 8 )
    {
      tra = v31->value.VS._1.ITr;
    }
    else
    {
      if ( v32 == 9 )
        ValueTraits = v31->value.VS._1.ITr;
      else
        ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                       this->CF->pFile->VMRef,
                                                                       v31);
LABEL_78:
      tra = ValueTraits;
    }
    if ( tra )
    {
      v35 = this->CF->pFile->VMRef;
      if ( tra == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v35->TraitsClassClass.pObject )
        tra = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v35->TraitsObject.pObject;
    }
    Flags = v33->Flags;
    v37 = v33->Flags & 0x1F;
    v91 = v37;
    if ( v37 )
    {
      if ( (unsigned int)(v37 - 8) < 2 )
        v38 = v33->value.VS._1.ITr;
      else
        v38 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                               this->CF->pFile->VMRef,
                                                               v33);
    }
    else
    {
      v38 = this->CF->pFile->VMRef->TraitsVoid.pObject;
    }
    to_tra = v38;
    if ( v38 )
    {
      v39 = this->CF->pFile->VMRef;
      if ( v38 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v39->TraitsClassClass.pObject )
      {
        v38 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v39->TraitsObject.pObject;
        to_tra = v38;
      }
    }
    fromb = 0;
    if ( (((unsigned __int8)BYTE1(v31->Flags) ^ BYTE1(Flags)) & 1) != 0 )
      goto LABEL_119;
    if ( tra != v38 )
    {
      if ( !v32 )
      {
LABEL_130:
        Scaleform::GFx::AS3::Value::Assign(v31, v33);
        goto LABEL_131;
      }
      v40 = this->CF->pFile->VMRef;
      v41 = v40->TraitsObject.pObject->ITraits.pObject;
      if ( tra == v41 || tra == v40->TraitsClassClass.pObject->ITraits.pObject )
        goto LABEL_131;
      if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, to_tra) )
      {
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v31, v33, v41);
        goto LABEL_131;
      }
      tob = Scaleform::GFx::AS3::Tracer::IsNumericType(this, tra);
      if ( tob && Scaleform::GFx::AS3::Tracer::IsNumericType(this, to_tra) )
      {
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v31, v33, v40->TraitsNumber.pObject->ITraits.pObject);
        goto LABEL_131;
      }
      if ( (unsigned int)(v95 - 12) > 3 || v31->value.VS._1.VInt )
      {
        v42 = v40->TraitsNull.pObject;
        v43 = tra;
        if ( tra != v42 )
        {
          if ( (unsigned int)(v91 - 12) <= 3 && !v33->value.VS._1.VInt || to_tra == v42 )
          {
            if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, tra) && tob )
              goto LABEL_119;
          }
          else
          {
            for ( k = tra; k; k = (Scaleform::GFx::AS3::InstanceTraits::Traits *)k->pParent.pObject )
              k->Flags |= 0x80u;
            v45 = (Scaleform::GFx::AS3::ClassTraits::Traits *)to_tra;
            if ( to_tra )
            {
              while ( (v45->Flags & 0x80) == 0 )
              {
                v45 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v45->pParent.pObject;
                if ( !v45 )
                  goto LABEL_116;
              }
              fromb = 1;
              if ( (v45->Flags & 0x20) != 0 )
                Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v31, v33, v45);
              else
                Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
                  this,
                  v31,
                  v33,
                  (Scaleform::GFx::AS3::InstanceTraits::Traits *)v45);
              v43 = tra;
            }
LABEL_116:
            for ( m = v43; m; m = (Scaleform::GFx::AS3::InstanceTraits::Traits *)m->pParent.pObject )
              m->Flags &= ~0x80u;
            if ( !fromb )
            {
LABEL_119:
              Scaleform::GFx::AS3::Tracer::ThrowMergeTypeError(this, tra, to_tra);
              v47 = this->CF->pFile->VMRef;
              Scaleform::GFx::AS3::VM::Error::Error(
                &v98,
                eScopeDepthUnbalancedError,
                (Scaleform::String)v47,
                to_st->ScopeStack.Data.Size,
                from_st->ScopeStack.Data.Size);
              Scaleform::GFx::AS3::VM::ThrowErrorInternal(
                v47,
                v48,
                (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
              pNode = v98.Message.pNode;
              --v98.Message.pNode->RefCount;
              if ( !pNode->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
              goto LABEL_121;
            }
          }
          goto LABEL_131;
        }
      }
      if ( ((unsigned int)(v91 - 12) > 3 || v33->value.VS._1.VInt) && to_tra != v40->TraitsNull.pObject )
      {
        if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, to_tra)
          && Scaleform::GFx::AS3::Tracer::IsNumericType(this, to_tra) )
        {
          goto LABEL_119;
        }
        goto LABEL_130;
      }
    }
LABEL_131:
    State = (Scaleform::GFx::AS3::TR::State *)from_st;
    v28 = v85;
    v27 = v88;
    goto LABEL_132;
  }
LABEL_133:
  v5 = to_st;
LABEL_134:
  v51 = State->Registers.Data.Size;
  if ( v5->Registers.Data.Size != v51 )
  {
LABEL_121:
    v50 = result;
    result->Result = 0;
    return v50;
  }
  v52 = 0;
  v86 = 0;
  if ( !v51 )
  {
LABEL_207:
    v50 = result;
    result->Result = 1;
    return v50;
  }
  v53 = 0;
  v89 = 0;
  while ( 2 )
  {
    v54 = &v5->Registers.Data;
    if ( v52 >= v54->Size )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        v54,
        (Scaleform::GFx::AS3::Value *)((char *)State->Registers.Data.Data + v53));
LABEL_205:
      v52 = v86 + 1;
      v53 += 16;
      v86 = v52;
      v89 = v53;
      if ( v52 >= State->Registers.Data.Size )
        goto LABEL_207;
      v5 = to_st;
      continue;
    }
    break;
  }
  v55 = (Scaleform::GFx::AS3::Value *)((char *)v54->Data + v53);
  v56 = v55->Flags & 0x1F;
  v57 = (Scaleform::GFx::AS3::Value *)((char *)State->Registers.Data.Data + v53);
  v92 = v56;
  if ( !v56 )
  {
    v58 = this->CF->pFile->VMRef->TraitsVoid.pObject;
    goto LABEL_144;
  }
  if ( (unsigned int)(v56 - 8) < 2 )
  {
    v58 = v55->value.VS._1.ITr;
LABEL_144:
    trb = v58;
    goto LABEL_145;
  }
  v58 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                         this->CF->pFile->VMRef,
                                                         v55);
  trb = v58;
LABEL_145:
  if ( v58 )
  {
    v59 = this->CF->pFile->VMRef;
    if ( v58 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v59->TraitsClassClass.pObject )
    {
      v58 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v59->TraitsObject.pObject;
      trb = v58;
    }
  }
  v60 = v57->Flags & 0x1F;
  v93 = v60;
  if ( !v60 )
  {
    v61 = this->CF->pFile->VMRef->TraitsVoid.pObject;
    goto LABEL_153;
  }
  if ( (unsigned int)(v60 - 8) < 2 )
  {
    v61 = v57->value.VS._1.ITr;
LABEL_153:
    to_trb = v61;
    goto LABEL_154;
  }
  v61 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                         this->CF->pFile->VMRef,
                                                         v57);
  to_trb = v61;
LABEL_154:
  if ( v61 )
  {
    v62 = this->CF->pFile->VMRef;
    if ( v61 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v62->TraitsClassClass.pObject )
    {
      v61 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v62->TraitsObject.pObject;
      to_trb = v61;
    }
  }
  v63 = 1 << (v86 & 7);
  v96 = v86 & 7;
  pData = from_st->RegistersAlive.pData;
  fromc = 0;
  v97 = v86 >> 3;
  v98.ID = v63;
  if ( ((unsigned __int8)v63 & pData[v86 >> 3]) == 0 )
    goto LABEL_198;
  if ( ((unsigned __int8)v63 & to_st->RegistersAlive.pData[v86 >> 3]) == 0 )
    goto LABEL_197;
  if ( v58 == v61 )
    goto LABEL_198;
  if ( !v92 )
  {
LABEL_197:
    Scaleform::GFx::AS3::Value::Assign(v55, v57);
    goto LABEL_198;
  }
  v65 = this->CF->pFile->VMRef;
  v66 = v65->TraitsObject.pObject->ITraits.pObject;
  if ( trb == v66 || trb == v65->TraitsClassClass.pObject->ITraits.pObject )
    goto LABEL_198;
  if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, to_trb) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v55, v57, v66);
    goto LABEL_198;
  }
  toc = Scaleform::GFx::AS3::Tracer::IsNumericType(this, trb);
  if ( toc && Scaleform::GFx::AS3::Tracer::IsNumericType(this, to_trb) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v55, v57, v65->TraitsNumber.pObject->ITraits.pObject);
    goto LABEL_198;
  }
  if ( (unsigned int)(v92 - 12) <= 3 && !v55->value.VS._1.VInt || (v67 = v65->TraitsNull.pObject, v68 = trb, trb == v67) )
  {
    if ( (unsigned int)(v93 - 12) <= 3 && !v57->value.VS._1.VInt || to_trb == v65->TraitsNull.pObject )
      goto LABEL_198;
    v72 = to_trb;
    if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, to_trb)
      && Scaleform::GFx::AS3::Tracer::IsNumericType(this, to_trb) )
    {
      goto LABEL_188;
    }
    goto LABEL_197;
  }
  if ( (unsigned int)(v93 - 12) <= 3 && !v57->value.VS._1.VInt || to_trb == v67 )
  {
    if ( !Scaleform::GFx::AS3::Tracer::IsStringType(this, trb) && toc )
      goto LABEL_187;
    goto LABEL_198;
  }
  for ( n = trb; n; n = (Scaleform::GFx::AS3::InstanceTraits::Traits *)n->pParent.pObject )
    n->Flags |= 0x80u;
  v70 = (Scaleform::GFx::AS3::ClassTraits::Traits *)to_trb;
  if ( to_trb )
  {
    while ( (v70->Flags & 0x80) == 0 )
    {
      v70 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v70->pParent.pObject;
      if ( !v70 )
        goto LABEL_184;
    }
    fromc = 1;
    if ( (v70->Flags & 0x20) != 0 )
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v55, v57, v70);
    else
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
        this,
        v55,
        v57,
        (Scaleform::GFx::AS3::InstanceTraits::Traits *)v70);
    v68 = trb;
  }
LABEL_184:
  for ( ii = v68; ii; ii = (Scaleform::GFx::AS3::InstanceTraits::Traits *)ii->pParent.pObject )
    ii->Flags &= ~0x80u;
  if ( fromc )
  {
LABEL_198:
    v73 = (v98.ID & from_st->RegistersAlive.pData[v97]) != 0 || (v98.ID & to_st->RegistersAlive.pData[v97]) != 0;
    v53 = v89;
    State = (Scaleform::GFx::AS3::TR::State *)from_st;
    v74 = to_st->RegistersAlive.pData;
    if ( v73 )
      v74[v97] |= 1 << v96;
    else
      v74[v97] &= ~(1 << v96);
    goto LABEL_205;
  }
LABEL_187:
  v72 = to_trb;
LABEL_188:
  Scaleform::GFx::AS3::Tracer::ThrowMergeTypeError(this, trb, v72);
  v50 = result;
  result->Result = 0;
  return v50;
}
