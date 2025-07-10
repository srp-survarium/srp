char __thiscall Scaleform::GFx::AS3::Tracer::SubstituteOpCode(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::VM *opcode,
        unsigned int *bcp,
        Scaleform::GFx::AS3::TR::State *st)
{
  unsigned int v5; // ebx
  const Scaleform::GFx::AS3::Value *Undefined; // eax
  Scaleform::GFx::AS3::Value *v8; // edi
  Scaleform::GFx::AS3::Value *v9; // edi
  int v10; // ebx
  bool v11; // al
  Scaleform::GFx::AS3::VM *v12; // eax
  Scaleform::GFx::AS3::VMAbcFile *v13; // edx
  Scaleform::GFx::AS3::Abc::File *v14; // ecx
  Scaleform::GFx::AS3::Value *v15; // edi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v16; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *v17; // ebp
  Scaleform::GFx::AS3::VM *v18; // esi
  const Scaleform::GFx::AS3::VM::Error *v19; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v21; // ebx
  unsigned int v22; // eax
  Scaleform::GFx::AS3::Value::TraceNullType CanBeNull; // eax
  const unsigned __int8 *v24; // ecx
  int v25; // ecx
  unsigned int v26; // eax
  int v27; // ecx
  unsigned int v28; // ebp
  Scaleform::GFx::AS3::BuiltinTraitsType v29; // eax
  int v30; // ebx
  Scaleform::GFx::AS3::VMAbcFile *v31; // edi
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  int v33; // eax
  int v34; // edi
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  int v36; // eax
  const unsigned __int8 *v37; // eax
  int v38; // eax
  const unsigned __int8 *v39; // ecx
  int v40; // edi
  Scaleform::GFx::AS3::VM *v41; // edx
  Scaleform::GFx::AS3::Abc::Code::OpCode OrigValueConsumer; // ebx
  int v43; // eax
  const unsigned __int8 *v44; // eax
  int v45; // eax
  unsigned int v46; // ebx
  unsigned int v47; // eax
  Scaleform::GFx::AS3::VMAbcFile *v48; // edi
  int v49; // eax
  unsigned int v50; // eax
  const unsigned __int8 *v51; // ecx
  unsigned int v52; // eax
  Scaleform::GFx::AS3::VMAbcFile *v53; // edi
  unsigned int v54; // ebp
  int v55; // eax
  Scaleform::GFx::AS3::Value::V1U v56; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // edi
  unsigned int v60; // ecx
  unsigned int Flags; // eax
  const Scaleform::GFx::AS3::Value *v62; // ecx
  bool IsSIntType; // al
  unsigned int Size; // edx
  Scaleform::GFx::AS3::Value *v65; // ecx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v66; // edi
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v68; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v69; // eax
  Scaleform::GFx::AS3::Value::V1U *v70; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v71; // edx
  const unsigned __int8 *v72; // [esp-8h] [ebp-188h]
  const unsigned __int8 *v73; // [esp-8h] [ebp-188h]
  const unsigned __int8 *v74; // [esp-8h] [ebp-188h]
  const unsigned __int8 *pCode; // [esp-8h] [ebp-188h]
  const unsigned __int8 *v76; // [esp-8h] [ebp-188h]
  const unsigned __int8 *v77; // [esp-8h] [ebp-188h]
  const unsigned __int8 *v78; // [esp-8h] [ebp-188h]
  unsigned int mn_index; // [esp+10h] [ebp-170h] BYREF
  unsigned int ccp; // [esp+14h] [ebp-16Ch] BYREF
  Scaleform::GFx::AS3::Value class_; // [esp+18h] [ebp-168h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+28h] [ebp-158h]
  const Scaleform::GFx::AS3::Traits *_2tr; // [esp+2Ch] [ebp-154h]
  Scaleform::GFx::AS3::CheckResult v84; // [esp+32h] [ebp-14Eh] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [esp+33h] [ebp-14Dh] BYREF
  unsigned int slot_ind; // [esp+34h] [ebp-14Ch] BYREF
  Scaleform::GFx::AS3::TR::ReadMnObject args; // [esp+38h] [ebp-148h] BYREF
  Scaleform::GFx::AS3::Value v88; // [esp+78h] [ebp-108h] BYREF
  Scaleform::GFx::AS3::Value _1; // [esp+88h] [ebp-F8h] BYREF
  Scaleform::GFx::AS3::Value _2; // [esp+98h] [ebp-E8h] BYREF
  Scaleform::GFx::AS3::VM::Error v91; // [esp+A8h] [ebp-D8h] BYREF
  Scaleform::GFx::AS3::TR::ReadArgsMnObject v92; // [esp+B0h] [ebp-D0h] BYREF

  switch ( (unsigned int)opcode )
  {
    case 4u:
    case 0x66u:
      pCode = this->pCode;
      mn_index = *bcp;
      v34 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, &mn_index);
      pFile = this->CF->pFile;
      args.VMRef = pFile->VMRef;
      args.StateRef = st;
      args.Num = 0;
      args.File = pFile;
      Scaleform::GFx::AS3::Multiname::Multiname(
        &args.ArgMN,
        pFile,
        &pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v34]);
      v36 = Scaleform::GFx::AS3::TR::StackReader::Read(&args, &args.ArgMN);
      args.Num += v36;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        (Scaleform::GFx::AS3::Value *)&args.ArgObject);
      ++args.Num;
      if ( Scaleform::GFx::AS3::Tracer::EmitGetProperty(this, opcode, st, &args, v34) )
      {
        Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, mn_index);
        Scaleform::GFx::AS3::TR::ReadMnObject::~ReadMnObject(&args);
        return 1;
      }
      else
      {
        Scaleform::GFx::AS3::TR::ReadMnObject::~ReadMnObject(&args);
        return 0;
      }
    case 5u:
    case 0x61u:
    case 0x68u:
      v74 = this->pCode;
      mn_index = *bcp;
      v30 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v74, &mn_index);
      v31 = this->CF->pFile;
      VMRef = v31->VMRef;
      args.StateRef = st;
      args.VMRef = VMRef;
      args.Num = 0;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        (Scaleform::GFx::AS3::Value *)&args.ArgMN);
      ++args.Num;
      args.ArgMN.Name.value.VS._1.VInt = (int)v31;
      Scaleform::GFx::AS3::Multiname::Multiname(
        (Scaleform::GFx::AS3::Multiname *)&args.ArgObject,
        v31,
        &v31->File.pObject->Const_Pool.const_multiname.Data.Data[v30]);
      v33 = Scaleform::GFx::AS3::TR::StackReader::Read(&args, (Scaleform::GFx::AS3::Multiname *)&args.ArgObject);
      args.Num += v33;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        &v88);
      ++args.Num;
      if ( Scaleform::GFx::AS3::Tracer::EmitSetProperty(
             this,
             (const Scaleform::GFx::AS3::Traits *)opcode,
             (const Scaleform::GFx::AS3::TR::ReadValueMnObject *)&args,
             v30) )
      {
        Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, mn_index);
        Scaleform::GFx::AS3::TR::ReadValueMnObject::~ReadValueMnObject((Scaleform::GFx::AS3::TR::ReadValueMnObject *)&args);
        return 1;
      }
      else
      {
        Scaleform::GFx::AS3::TR::ReadValueMnObject::~ReadValueMnObject((Scaleform::GFx::AS3::TR::ReadValueMnObject *)&args);
        return 0;
      }
    case 8u:
      v5 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, bcp);
      Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
      Scaleform::GFx::AS3::TR::State::SetRegister(st, (Scaleform::GFx::AS3::AbsoluteIndex)v5, Undefined);
      Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341>>::Clear(&st->RegistersAlive, v5);
      Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, *bcp);
      return 1;
    case 0x45u:
    case 0x46u:
    case 0x4Cu:
    case 0x4Eu:
    case 0x4Fu:
      v77 = this->pCode;
      mn_index = *bcp;
      v46 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v77, &mn_index);
      v47 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &mn_index);
      v48 = this->CF->pFile;
      Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v92, v48->VMRef, st, v47);
      v92.File = v48;
      Scaleform::GFx::AS3::Multiname::Multiname(
        &v92.ArgMN,
        v48,
        &v48->File.pObject->Const_Pool.const_multiname.Data.Data[v46]);
      v49 = Scaleform::GFx::AS3::TR::StackReader::Read(&v92, &v92.ArgMN);
      v92.Num += v49;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        (Scaleform::GFx::AS3::Value *)&v92.ArgObject);
      ++v92.Num;
      if ( !Scaleform::GFx::AS3::Tracer::EmitCall(this, (Scaleform::GFx::AS3::Abc::Code::OpCode)opcode, st, &v92, v46) )
        goto LABEL_78;
      Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, mn_index);
      goto LABEL_66;
    case 0x4Au:
      v78 = this->pCode;
      ccp = *bcp;
      v50 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v78, &ccp);
      v51 = this->pCode;
      mn_index = v50;
      v52 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v51, &ccp);
      v53 = this->CF->pFile;
      v54 = v52;
      Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v92, v53->VMRef, st, v52);
      v92.File = v53;
      Scaleform::GFx::AS3::Multiname::Multiname(
        &v92.ArgMN,
        v53,
        &v53->File.pObject->Const_Pool.const_multiname.Data.Data[mn_index]);
      v55 = Scaleform::GFx::AS3::TR::StackReader::Read(&v92, &v92.ArgMN);
      v92.Num += v55;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        (Scaleform::GFx::AS3::Value *)&v92.ArgObject);
      ++v92.Num;
      if ( Scaleform::GFx::AS3::Multiname::IsRunTime(&v92.ArgMN) )
        goto LABEL_79;
      if ( (v92.ArgObject.Flags & 0x400) != 0 )
      {
        if ( (v92.ArgObject.Flags & 0x1F) != 9 )
        {
          if ( (v92.ArgObject.Flags & 0x1F) == 0xD )
          {
            Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_construct, v54);
            v56 = *(Scaleform::GFx::AS3::Value::V1U *)(*(_DWORD *)(v92.ArgObject.value.VS._1.VInt + 20) + 100);
            class_.Bonus.pWeakProxy = 0;
            class_.value.VS._1 = v56;
            class_.Flags = 8;
LABEL_72:
            Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &st->OpStack.Data,
              &class_);
            Scaleform::GFx::AS3::Value::~Value(&class_);
            Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
LABEL_66:
            Scaleform::GFx::AS3::TR::ReadArgsMnObject::~ReadArgsMnObject(&v92);
            return 1;
          }
LABEL_79:
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_constructprop, mn_index, v54);
          pObject = this->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
          class_.Bonus.pWeakProxy = 0;
          class_.value.VS._1.VInt = (int)pObject;
          class_.Flags = 8;
          Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &st->OpStack.Data,
            &class_);
          Scaleform::GFx::AS3::Value::~Value(&class_);
          Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
          goto LABEL_66;
        }
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_construct, v54);
        class_.value.VS._1.VInt = *(_DWORD *)(v92.ArgObject.value.VS._1.VInt + 100);
        class_.Bonus.pWeakProxy = 0;
        class_.Flags = 8;
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &st->OpStack.Data,
          &class_);
        Scaleform::GFx::AS3::Value::~Value(&class_);
        Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
        Scaleform::GFx::AS3::TR::ReadArgsMnObject::~ReadArgsMnObject(&v92);
        return 1;
      }
      else
      {
        if ( v54 )
          goto LABEL_79;
        vm = this->CF->pFile->VMRef;
        _2tr = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &v92.ArgObject, 0);
        vm = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::AS3::FindFixedSlot(
                                          (const Scaleform::GFx::AS3::SlotInfo *)vm,
                                          _2tr,
                                          (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&v92.ArgMN,
                                          &slot_ind,
                                          0);
        if ( !vm )
          goto LABEL_79;
        Scaleform::GFx::AS3::Tracer::EmitGetAbsSlot(this, st, slot_ind);
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_construct, 0);
        class_.Flags = 0;
        class_.Bonus.pWeakProxy = 0;
        if ( Scaleform::GFx::AS3::TR::State::GetPropertyType(
               st,
               &v84,
               (Scaleform::GFx::AS3::Traits *)_2tr,
               (Scaleform::GFx::AS3::SlotInfo *)vm,
               &class_)->Result )
          goto LABEL_72;
        Scaleform::GFx::AS3::Value::~Value(&class_);
LABEL_78:
        Scaleform::GFx::AS3::TR::ReadArgsMnObject::~ReadArgsMnObject(&v92);
        return 0;
      }
    case 0x5Du:
      v37 = this->pCode;
      mn_index = *bcp;
      v38 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v37, &mn_index);
      v39 = this->pCode;
      v40 = v38;
      ccp = mn_index;
      v41 = (Scaleform::GFx::AS3::VM *)v39[mn_index];
      ccp = mn_index + 1;
      vm = v41;
      OrigValueConsumer = Scaleform::GFx::AS3::Tracer::GetOrigValueConsumer(this, mn_index);
      if ( vm == (Scaleform::GFx::AS3::VM *)102 )
      {
        Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &ccp);
        if ( Scaleform::GFx::AS3::Tracer::EmitFindProperty(this, st, v40, 1, OrigValueConsumer) )
        {
          Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
          return 1;
        }
      }
      else if ( Scaleform::GFx::AS3::Tracer::EmitFindProperty(this, st, v40, 0, OrigValueConsumer) )
      {
        goto LABEL_63;
      }
$LN942:
      v76 = this->pCode;
      mn_index = *bcp;
      v43 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v76, &mn_index);
      if ( !Scaleform::GFx::AS3::Tracer::EmitFindProperty(this, st, v43, 0, op_nop) )
        return 0;
LABEL_63:
      Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, mn_index);
      return 1;
    case 0x5Eu:
      goto $LN942;
    case 0x60u:
      v44 = this->pCode;
      mn_index = *bcp;
      v45 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v44, &mn_index);
      if ( Scaleform::GFx::AS3::Tracer::EmitFindProperty(this, st, v45, 1, op_nop) )
        goto LABEL_63;
      return 0;
    case 0x62u:
      v73 = this->pCode;
      mn_index = *bcp;
      v29 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v73, &mn_index);
      return Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(this, bcp, mn_index, st, v29);
    case 0x64u:
      v24 = this->pCode;
      ccp = *bcp;
      v25 = v24[ccp++];
      if ( v25 == 108 )
      {
        Scaleform::GFx::AS3::TR::State::exec_getglobalscope(st);
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getglobalslot);
        v26 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &ccp);
        Scaleform::GFx::AS3::TR::State::exec_getslot(st, v26);
        Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
        return 1;
      }
      if ( v25 != 43 )
        return 0;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        &this->OrigOpcodePos,
        &ccp);
      v27 = this->pCode[ccp++];
      if ( v27 == 109 )
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_setglobalslot);
        v28 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &ccp);
        Scaleform::GFx::AS3::TR::State::exec_getglobalscope(st);
        Scaleform::GFx::AS3::TR::State::SwapOp(st);
        Scaleform::GFx::AS3::TR::State::exec_setslot(st, v28);
        Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
        return 1;
      }
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy>>::PopBack(
        &this->OrigOpcodePos,
        1u);
      return 0;
    case 0x70u:
      Size = st->OpStack.Data.Size;
      v65 = &st->OpStack.Data.Data[Size - 1];
      if ( ((v65->Flags & 0x1F) - 12 > 3 || v65->value.VS._1.VInt)
        && !Scaleform::GFx::AS3::Tracer::IsStringType(this, &st->OpStack.Data.Data[Size - 1]) )
      {
        return 0;
      }
      Scaleform::GFx::AS3::TR::State::ConvertOpTo(
        st,
        this->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject,
        NullOrNot);
      Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, *bcp);
      return 1;
    case 0x73u:
      IsSIntType = Scaleform::GFx::AS3::Tracer::IsSIntType(this, &st->OpStack.Data.Data[st->OpStack.Data.Size - 1]);
      goto LABEL_96;
    case 0x74u:
      if ( Scaleform::GFx::AS3::Tracer::IsUIntType(this, &st->OpStack.Data.Data[st->OpStack.Data.Size - 1]) )
        goto LABEL_6;
      return 0;
    case 0x75u:
      IsSIntType = Scaleform::GFx::AS3::Tracer::IsNumberType(this, &st->OpStack.Data.Data[st->OpStack.Data.Size - 1]);
LABEL_96:
      if ( IsSIntType )
        goto LABEL_97;
      return 0;
    case 0x76u:
      if ( !Scaleform::GFx::AS3::Tracer::IsBooleanType(this, &st->OpStack.Data.Data[st->OpStack.Data.Size - 1]) )
        return 0;
LABEL_97:
      Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, *bcp);
      return 1;
    case 0x80u:
      v72 = this->pCode;
      ccp = *bcp;
      v12 = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v72, &ccp);
      v13 = this->CF->pFile;
      v14 = v13->File.pObject;
      vm = v12;
      v15 = &st->OpStack.Data.Data[st->OpStack.Data.Size - 1];
      v16 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
              v13->VMRef,
              v13,
              &v14->Const_Pool.const_multiname.Data.Data[(_DWORD)v12]);
      v17 = v16;
      if ( v16 )
      {
        v21 = v16->ITraits.pObject;
        v22 = v15->Flags & 0x1F;
        mn_index = v22;
        if ( !v22 && v21 != this->CF->pFile->VMRef->TraitsClassClass.pObject->ITraits.pObject )
        {
          if ( !Scaleform::GFx::AS3::Tracer::IsNotObjectType(this, v21)
            && Scaleform::GFx::AS3::Tracer::GetNewTopOpCode(this, 0) == 33 )
          {
            this->WCode->Data.Data[this->WCode->Data.Size - 1] = 32;
            Scaleform::GFx::AS3::TR::State::ConvertOpTo(st, v21, Null);
            Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
            return 1;
          }
          v22 = mn_index;
        }
        if ( v22 - 12 <= 3 && !v15->value.VS._1.VInt || Scaleform::GFx::AS3::Tracer::ValueIsOfType(this, v15, v17) )
        {
          CanBeNull = Scaleform::GFx::AS3::Tracer::CanBeNull(this, v21);
          if ( (v15->Flags & 0x1F) - 12 <= 3 && !v15->value.VS._1.VInt )
            CanBeNull = Null;
          Scaleform::GFx::AS3::TR::State::ConvertOpTo(st, v21, CanBeNull);
          Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
          return 1;
        }
        else
        {
          Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_coerce, (unsigned int)vm);
          Scaleform::GFx::AS3::TR::State::ConvertOpTo(st, v21, NullOrNot);
          return 1;
        }
      }
      else
      {
        v18 = this->CF->pFile->VMRef;
        Scaleform::GFx::AS3::VM::Error::Error(&v91, eClassNotFoundError, v18);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v18,
          v19,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
        pNode = v91.Message.pNode;
        --v91.Message.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        return 1;
      }
    case 0x82u:
      v8 = &st->OpStack.Data.Data[st->OpStack.Data.Size - 1];
      if ( Scaleform::GFx::AS3::Tracer::IsSIntType(this, v8) || Scaleform::GFx::AS3::Tracer::IsUIntType(this, v8) )
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_convert_d);
        if ( Scaleform::GFx::AS3::Value::IsInt(v8) )
          Scaleform::GFx::AS3::Value::ToNumberValue(v8, &result);
        else
          Scaleform::GFx::AS3::TR::State::ConvertOpTo(
            st,
            this->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
            NotNull);
        return 1;
      }
      else
      {
LABEL_6:
        Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, *bcp);
        return 1;
      }
    case 0x85u:
      v9 = &st->OpStack.Data.Data[st->OpStack.Data.Size - 1];
      v10 = v9->Flags & 0x1F;
      if ( v10 == 10 )
        return 1;
      if ( ((unsigned int)(v10 - 12) > 3 || v9->value.VS._1.VInt)
        && !Scaleform::GFx::AS3::Tracer::IsStringType(this, v9) )
      {
        return 0;
      }
      v11 = (unsigned int)(v10 - 12) <= 3 && v9->value.VS._1.VInt == 0;
      Scaleform::GFx::AS3::TR::State::ConvertOpTo(
        st,
        this->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject,
        (Scaleform::GFx::AS3::Value::TraceNullType)(!v11 + 1));
      Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, *bcp);
      return 1;
    case 0x87u:
      p_OpStack = &st->OpStack;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        &class_);
      switch ( class_.Flags & 0x1F )
      {
        case 8:
          ITr = class_.value.VS._1.ITr;
          break;
        case 9:
          ITr = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(class_.value.VS._1.VInt + 100);
          break;
        case 13:
          ITr = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(*(_DWORD *)(class_.value.VS._1.VInt + 20) + 100);
          break;
        default:
LABEL_93:
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_astypelate);
          Scaleform::GFx::AS3::Value::~Value(&class_);
          return 1;
      }
      if ( !ITr )
        goto LABEL_93;
      v60 = st->OpStack.Data.Size;
      Flags = p_OpStack->Data.Data[v60 - 1].Flags;
      v62 = &p_OpStack->Data.Data[v60 - 1];
      if ( ((Flags & 0x1F) - 12 > 3 || v62->value.VS._1.VInt)
        && !Scaleform::GFx::AS3::Tracer::ValueIsOfType(this, v62, ITr) )
      {
        if ( Scaleform::GFx::AS3::Tracer::IsNotRefCountedType(this, ITr) )
          ITr = this->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
        Scaleform::GFx::AS3::TR::State::ConvertOpTo(st, ITr, NullOrNot);
        goto LABEL_93;
      }
      Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(this, st);
      Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, *bcp);
      Scaleform::GFx::AS3::TR::State::ConvertOpTo(st, ITr, NullOrNot);
      Scaleform::GFx::AS3::Value::~Value(&class_);
      return 1;
    case 0xA0u:
      v66 = &st->OpStack;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        &_2);
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        &_1);
      ValueTraits = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &_1, 0);
      v68 = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &_2, 0);
      v69 = this->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject;
      _2tr = v68;
      if ( ValueTraits == v69 || v68 == v69 )
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_add);
        v70 = (Scaleform::GFx::AS3::Value::V1U *)this->CF->pFile->VMRef->TraitsString.pObject;
        class_.Flags = 72;
      }
      else
      {
        if ( !Scaleform::GFx::AS3::Tracer::IsNumberType(this, &_1)
          || !Scaleform::GFx::AS3::Tracer::IsNumberType(this, &_2) )
        {
          if ( this->pCode[*bcp] == 117 )
          {
            Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_add_d);
            Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, *bcp + 1);
          }
          else
          {
            if ( Scaleform::GFx::AS3::Tracer::IsSIntType(this, &_1)
              && Scaleform::GFx::AS3::Tracer::IsSIntType(this, &_2) )
            {
              Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_add_ti);
              v71 = this->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject;
              class_.Bonus.pWeakProxy = 0;
              class_.value.VS._1.VInt = (int)v71;
              class_.Flags = 8;
              Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
                &v66->Data,
                &class_);
              goto LABEL_125;
            }
            Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_add);
            if ( !Scaleform::GFx::AS3::Tracer::IsPrimitiveType(this, ValueTraits)
              || !Scaleform::GFx::AS3::Tracer::IsPrimitiveType(
                    this,
                    (Scaleform::GFx::AS3::InstanceTraits::Traits *)_2tr) )
            {
              v70 = (Scaleform::GFx::AS3::Value::V1U *)this->CF->pFile->VMRef->TraitsObject.pObject;
              class_.Bonus.pWeakProxy = 0;
              class_.Flags = 72;
              goto LABEL_124;
            }
          }
          v70 = (Scaleform::GFx::AS3::Value::V1U *)this->CF->pFile->VMRef->TraitsNumber.pObject;
          class_.Bonus.pWeakProxy = 0;
          class_.Flags = 8;
          goto LABEL_124;
        }
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_add_td);
        v70 = (Scaleform::GFx::AS3::Value::V1U *)this->CF->pFile->VMRef->TraitsNumber.pObject;
        class_.Flags = 8;
      }
      class_.Bonus.pWeakProxy = 0;
LABEL_124:
      class_.value.VS._1 = v70[25];
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &v66->Data,
        &class_);
LABEL_125:
      Scaleform::GFx::AS3::Value::~Value(&class_);
      Scaleform::GFx::AS3::Value::~Value(&_1);
      Scaleform::GFx::AS3::Value::~Value(&_2);
      return 1;
    case 0xD0u:
      return Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(this, bcp, *bcp, st, Traits_Unknown);
    case 0xD1u:
      return Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(this, bcp, *bcp, st, Traits_Boolean);
    case 0xD2u:
      return Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(this, bcp, *bcp, st, Traits_SInt);
    case 0xD3u:
      return Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(this, bcp, *bcp, st, Traits_UInt);
    default:
      return 0;
  }
}
