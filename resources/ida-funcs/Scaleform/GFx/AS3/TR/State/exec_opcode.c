void __thiscall Scaleform::GFx::AS3::TR::State::exec_opcode(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        unsigned int *bcp)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // ebx
  const unsigned __int8 *pCode; // ebp
  Scaleform::GFx::AS3::Tracer *v6; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::AS3::Value *Null; // eax
  Scaleform::GFx::AS3::Value *Undefined; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  unsigned int v14; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // eax
  unsigned int v16; // ebx
  unsigned int v17; // eax
  unsigned int v18; // eax
  int v19; // eax
  int v20; // eax
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v22; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v24; // eax
  int v25; // eax
  unsigned int v26; // eax
  int v27; // eax
  const Scaleform::GFx::AS3::Abc::ClassInfo *v28; // eax
  unsigned int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // eax
  unsigned int v39; // eax
  unsigned int v40; // eax
  Scaleform::GFx::AS3::Tracer *v41; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  Scaleform::GFx::AS3::Value::TraceNullType CanBeNull; // eax
  unsigned int v44; // eax
  unsigned int v45; // eax
  unsigned int v46; // eax
  unsigned int v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // eax
  unsigned int v50; // eax
  int v51; // eax
  int v52; // eax
  Scaleform::GFx::AS3::VM *v53; // esi
  const Scaleform::GFx::AS3::VM::Error *v54; // eax
  unsigned int v55; // esi
  unsigned int v56; // edi
  int v57; // [esp-4h] [ebp-34h]
  unsigned int v58; // [esp-4h] [ebp-34h]
  unsigned int v59; // [esp-4h] [ebp-34h]
  Scaleform::GFx::AS3::VM::Error v60; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v61; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+20h] [ebp-10h] BYREF

  pTracer = this->pTracer;
  pCode = this->pTracer->pCode;
  v6 = this->pTracer;
  this->OpcodeCP = *bcp - 1;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, opcode);
  switch ( opcode )
  {
    case op_throw:
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->OpStack.Data,
        this->OpStack.Data.Size - 1);
      return;
    case op_getsuper:
    case op_setsuper:
    case op_kill:
    case op_callsuper:
    case op_callproperty:
    case op_constructprop:
    case op_callproplex:
    case op_callsupervoid:
    case op_callpropvoid:
    case op_setproperty:
    case op_getproperty:
    case op_initproperty:
    case op_convert_o:
    case op_checkfilter:
    case op_coerce:
    case op_coerce_a:
    case op_astypelate:
    case op_add:
      return;
    case op_dxns:
      v7 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_dxns(this, v7);
      return;
    case op_dxnslate:
      Scaleform::GFx::AS3::TR::State::exec_dxnslate(this);
      return;
    case op_label:
      Scaleform::GFx::AS3::Tracer::AddBlock(pTracer, this, *bcp - 1, tUnknown, (Scaleform::GFx::AS3::TR::State *)1);
      Scaleform::GFx::AS3::Tracer::PopNewOpCode(pTracer);
      return;
    case op_ifnlt:
    case op_ifnle:
    case op_ifngt:
    case op_ifnge:
    case op_ifeq:
    case op_ifne:
    case op_iflt:
    case op_ifle:
    case op_ifgt:
    case op_ifge:
    case op_ifstricteq:
    case op_ifstrictne:
      Scaleform::GFx::AS3::TR::State::exec_if(this, bcp, opcode);
      return;
    case op_jump:
      Scaleform::GFx::AS3::TR::State::exec_jump(this, bcp);
      return;
    case op_iftrue:
    case op_iffalse:
      Scaleform::GFx::AS3::TR::State::exec_if_boolean(this, bcp, opcode);
      return;
    case op_lookupswitch:
      Scaleform::GFx::AS3::TR::State::exec_switch(this, bcp);
      return;
    case op_pushwith:
      Scaleform::GFx::AS3::TR::State::exec_pushwith(this);
      return;
    case op_popscope:
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->ScopeStack.Data,
        this->ScopeStack.Data.Size - 1);
      return;
    case op_nextname:
      Scaleform::GFx::AS3::TR::State::exec_nextname(this);
      return;
    case op_hasnext:
      Scaleform::GFx::AS3::TR::State::exec_hasnext(this);
      return;
    case op_pushnull:
      Null = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        Null);
      return;
    case op_pushundefined:
      Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        Undefined);
      return;
    case op_nextvalue:
      Scaleform::GFx::AS3::TR::State::exec_nextvalue(this);
      return;
    case op_pushbyte:
      v57 = pCode[(*bcp)++];
      Scaleform::GFx::AS3::TR::State::exec_pushbyte(this, v57);
      return;
    case op_pushshort:
      v10 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushshort(this, v10);
      return;
    case op_pushtrue:
      val.value.VS._1.VBool = 1;
      goto LABEL_20;
    case op_pushfalse:
      val.value.VS._1.VBool = 0;
LABEL_20:
      val.Bonus.pWeakProxy = 0;
      val.Flags = 1;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        &val);
      goto LABEL_21;
    case op_pushnan:
      val.Flags = 4;
      val.Bonus.pWeakProxy = 0;
      val.value.VNumber = Scaleform::GFx::NumberUtil::NaN();
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        &val);
LABEL_21:
      Scaleform::GFx::AS3::Value::~Value(&val);
      return;
    case op_pop:
      Scaleform::GFx::AS3::TR::State::exec_pop(this);
      return;
    case op_dup:
      Scaleform::GFx::AS3::TR::State::exec_dup(this);
      return;
    case op_swap:
      Scaleform::GFx::AS3::TR::State::SwapOp(this);
      return;
    case op_pushstring:
      v11 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushstring(this, v11);
      return;
    case op_pushint:
      v12 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushint(this, v12);
      return;
    case op_pushuint:
      v13 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushuint(this, v13);
      return;
    case op_pushdouble:
      v14 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushdouble(this, v14);
      return;
    case op_pushscope:
      Scaleform::GFx::AS3::TR::State::exec_pushscope(this);
      return;
    case op_pushnamespace:
      v15 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(
                                                               pCode,
                                                               bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushnamespace(this, v15);
      return;
    case op_hasnext2:
      v16 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      v17 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_hasnext2(this, v16, v17);
      return;
    case op_increment_tu:
    case op_decrement_tu:
    case op_inclocal_tu:
    case op_declocal_tu:
    case op_lf64:
    case op_si8:
    case op_si16:
    case op_si32:
    case op_sf32:
    case op_sf64:
    case op_sxi1:
    case op_sxi8:
    case op_sxi16:
      Scaleform::GFx::AS3::TR::State::exec_lf32(this);
      return;
    case op_newfunction:
      v18 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_newfunction(this, v18);
      return;
    case op_call:
      v19 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_call(this, v19);
      return;
    case op_construct:
      v20 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_construct(this, v20);
      return;
    case op_callmethod:
    case op_callstatic:
      VMRef = this->pTracer->CF->pFile->VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v60, eNotImplementedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        VMRef,
        v22,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
      pNode = v60.Message.pNode;
      goto LABEL_112;
    case op_returnvoid:
      Scaleform::GFx::AS3::Tracer::AddBlock(pTracer, this, *bcp, tDead, (Scaleform::GFx::AS3::TR::State *)1);
      return;
    case op_returnvalue:
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->OpStack.Data,
        this->OpStack.Data.Size - 1);
      Scaleform::GFx::AS3::Tracer::AddBlock(pTracer, this, *bcp, tDead, (Scaleform::GFx::AS3::TR::State *)1);
      return;
    case op_constructsuper:
      v24 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_constructsuper(this, v24);
      return;
    case op_applytype:
      v25 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_applytype(this, v25);
      return;
    case op_newobject:
      v26 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_newobject(this, v26);
      return;
    case op_newarray:
      v27 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_newarray(this, v27);
      return;
    case op_newactivation:
      Scaleform::GFx::AS3::TR::State::exec_newactivation(this);
      return;
    case op_newclass:
      v28 = (const Scaleform::GFx::AS3::Abc::ClassInfo *)Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_newclass(this, v28);
      return;
    case op_getdescendants:
      v29 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_getdescendants(this, v29);
      return;
    case op_newcatch:
    case op_getlex:
      v30 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_newcatch(this, v30);
      return;
    case op_findpropstrict:
      v31 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_findpropstrict(this, v31);
      return;
    case op_findproperty:
      v32 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_findproperty(this, v32);
      return;
    case op_getlocal:
      v48 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_getlocal(this, v48);
      return;
    case op_setlocal:
      v33 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_setlocal(this, v33);
      return;
    case op_getglobalscope:
      Scaleform::GFx::AS3::TR::State::exec_getglobalscope(this);
      return;
    case op_getscopeobject:
      v34 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_getscopeobject(this, v34);
      return;
    case op_deleteproperty:
      v35 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_deleteproperty(this, v35);
      return;
    case op_getslot:
      v36 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_getslot(this, v36);
      return;
    case op_setslot:
      v37 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_setslot(this, v37);
      return;
    case op_getglobalslot:
      v38 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_getglobalslot(this, v38);
      return;
    case op_setglobalslot:
      v39 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_setglobalslot(this, v39);
      return;
    case op_convert_s:
    case op_typeof:
      Scaleform::GFx::AS3::TR::State::exec_1OpString(this);
      return;
    case op_esc_xelem:
    case op_esc_xattr:
      Scaleform::GFx::AS3::TR::State::exec_esc_xelem(this);
      return;
    case op_convert_i:
      Scaleform::GFx::AS3::TR::State::exec_convert_i(this);
      return;
    case op_convert_u:
      Scaleform::GFx::AS3::TR::State::exec_convert_u(this);
      return;
    case op_convert_d:
      Scaleform::GFx::AS3::TR::State::exec_convert_d(this);
      return;
    case op_convert_b:
      Scaleform::GFx::AS3::TR::State::exec_convert_b(this);
      return;
    case op_coerce_s:
      Scaleform::GFx::AS3::TR::State::exec_coerce_s(this);
      return;
    case op_astype:
      v40 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_astype(this, v40);
      return;
    case op_negate:
      v41 = this->pTracer;
      pObject = this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject;
      if ( Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]) != pObject )
        goto LABEL_69;
      v41->WCode->Data.Data[v41->WCode->Data.Size - 1] = 84;
      return;
    case op_increment:
    case op_decrement:
      Scaleform::GFx::AS3::TR::State::exec_1OpNumber(this);
      return;
    case op_inclocal:
    case op_declocal:
      v44 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_convert_reg_d(this, v44);
      return;
    case op_not:
      v41 = this->pTracer;
      pObject = this->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject;
      if ( Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]) != pObject )
        goto LABEL_69;
      v41->WCode->Data.Data[v41->WCode->Data.Size - 1] = 34;
      return;
    case op_bitnot:
      Scaleform::GFx::AS3::TR::State::exec_1OpSInt(this);
      return;
    case op_add_d:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        this,
        this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
        op_add_td);
      return;
    case op_subtract:
      Scaleform::GFx::AS3::TR::State::exec_subtract(this);
      return;
    case op_multiply:
      Scaleform::GFx::AS3::TR::State::exec_multiply(this);
      return;
    case op_divide:
      Scaleform::GFx::AS3::TR::State::exec_divide(this);
      return;
    case op_modulo:
      Scaleform::GFx::AS3::TR::State::exec_2OpNumber(this);
      return;
    case op_lshift:
    case op_rshift:
    case op_bitand:
    case op_bitor:
    case op_bitxor:
      Scaleform::GFx::AS3::TR::State::exec_2OpSInt(this);
      return;
    case op_urshift:
      Scaleform::GFx::AS3::TR::State::exec_2OpUInt(this);
      return;
    case op_equals:
    case op_strictequals:
    case op_lessthan:
    case op_lessequals:
    case op_greaterthan:
    case op_greaterequals:
    case op_instanceof:
    case op_istypelate:
    case op_in:
      Scaleform::GFx::AS3::TR::State::exec_2OpBoolean(this);
      return;
    case op_istype:
      v45 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_istype(this, v45);
      return;
    case op_increment_i:
      v41 = this->pTracer;
      pObject = this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject;
      if ( Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]) != pObject )
        goto LABEL_69;
      v41->WCode->Data.Data[v41->WCode->Data.Size - 1] = 152;
      return;
    case op_decrement_i:
      v41 = this->pTracer;
      pObject = this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject;
      if ( Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]) != pObject )
        goto LABEL_69;
      v41->WCode->Data.Data[v41->WCode->Data.Size - 1] = 153;
      return;
    case op_inclocal_i:
      v46 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_inclocal_i(this, v46);
      return;
    case op_declocal_i:
      v47 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_declocal_i(this, v47);
      return;
    case op_negate_i:
      v41 = this->pTracer;
      pObject = this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject;
      if ( Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]) == pObject )
      {
        v41->WCode->Data.Data[v41->WCode->Data.Size - 1] = 63;
      }
      else
      {
LABEL_69:
        CanBeNull = Scaleform::GFx::AS3::Tracer::CanBeNull(v41, pObject);
        Scaleform::GFx::AS3::TR::State::ConvertOpTo(this, pObject, CanBeNull);
      }
      return;
    case op_add_i:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        this,
        this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_add_ti);
      return;
    case op_subtract_i:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        this,
        this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_subtract_ti);
      return;
    case op_multiply_i:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        this,
        this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_multiply_ti);
      return;
    case op_getlocal0:
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        this->Registers.Data.Data);
      return;
    case op_getlocal1:
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        this->Registers.Data.Data + 1);
      return;
    case op_getlocal2:
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        this->Registers.Data.Data + 2);
      return;
    case op_getlocal3:
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        this->Registers.Data.Data + 3);
      return;
    case op_setlocal0:
      Scaleform::GFx::AS3::TR::State::exec_setlocal0(this);
      return;
    case op_setlocal1:
      Scaleform::GFx::AS3::TR::State::exec_setlocal1(this);
      return;
    case op_setlocal2:
      Scaleform::GFx::AS3::TR::State::exec_setlocal2(this);
      return;
    case op_setlocal3:
      Scaleform::GFx::AS3::TR::State::exec_setlocal3(this);
      return;
    case op_debug:
      v58 = pCode[(*bcp)++];
      Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg(pTracer, v58);
      v49 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg(pTracer, v49);
      v59 = pCode[(*bcp)++];
      Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg(pTracer, v59);
      goto $LN4_119;
    case op_debugline:
    case op_debugfile:
      goto $LN4_119;
    case op_0xF2:
      Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      return;
    default:
      v51 = (char)(32 * *(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[opcode]) >> 5;
      if ( !v51 )
        return;
      v52 = v51 - 1;
      if ( v52 )
      {
        if ( v52 == 1 )
        {
          v55 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
          v56 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
          Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg(pTracer, v55);
          Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg(pTracer, v56);
        }
        else
        {
          v53 = this->pTracer->CF->pFile->VMRef;
          Scaleform::GFx::AS3::VM::Error::Error(&v61, eNotImplementedError, v53);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            v53,
            v54,
            (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
          pNode = v61.Message.pNode;
LABEL_112:
          if ( !--pNode->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
      }
      else
      {
$LN4_119:
        v50 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
        Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg(pTracer, v50);
      }
      return;
  }
}
