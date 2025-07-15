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
  const unsigned __int8 *v12; // edx
  Scaleform::GFx::AS3::VM *v13; // edi
  Scaleform::GFx::AS3::VMAbcFile *v14; // eax
  Scaleform::GFx::AS3::Abc::File *v15; // ecx
  Scaleform::GFx::AS3::Abc::Multiname *v16; // edi
  Scaleform::GFx::AS3::Value *v17; // ebx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v18; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v19; // ebp
  Scaleform::StringDataPtr *Name; // eax
  Scaleform::GFx::AS3::VM *v21; // esi
  const Scaleform::GFx::AS3::VM::Error *v22; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  char *v24; // edi
  unsigned int v25; // eax
  Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *WCode; // eax
  unsigned int v27; // edx
  unsigned int *Data; // eax
  Scaleform::GFx::AS3::Value::TraceNullType CanBeNull; // eax
  const unsigned __int8 *v30; // edx
  int v31; // ecx
  Scaleform::GFx::ASStringNode *v32; // eax
  int v33; // ecx
  unsigned int v34; // ebp
  const unsigned __int8 *v35; // ecx
  Scaleform::GFx::AS3::BuiltinTraitsType v36; // eax
  const unsigned __int8 *v37; // edx
  int v38; // ebx
  Scaleform::GFx::AS3::VMAbcFile *v39; // edi
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  int v41; // eax
  const unsigned __int8 *pCode; // ecx
  int v43; // edi
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  int v45; // eax
  const unsigned __int8 *v46; // eax
  int v47; // eax
  const unsigned __int8 *v48; // ecx
  int v49; // edi
  Scaleform::GFx::AS3::VM *v50; // edx
  Scaleform::GFx::AS3::Abc::Code::OpCode OrigValueConsumer; // ebx
  const unsigned __int8 *v52; // ecx
  int v53; // eax
  const unsigned __int8 *v54; // eax
  int v55; // eax
  const unsigned __int8 *v56; // eax
  unsigned int v57; // ebx
  unsigned int v58; // eax
  Scaleform::GFx::AS3::VMAbcFile *v59; // edi
  int v60; // eax
  const unsigned __int8 *v61; // edx
  unsigned int v62; // eax
  const unsigned __int8 *v63; // ecx
  unsigned int v64; // eax
  Scaleform::GFx::AS3::VMAbcFile *v65; // edi
  unsigned int v66; // ebp
  int v67; // eax
  Scaleform::GFx::AS3::Value::V1U v68; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // edi
  unsigned int v72; // ecx
  unsigned int Flags; // eax
  const Scaleform::GFx::AS3::Value *v74; // ecx
  bool IsSIntType; // al
  unsigned int *v76; // eax
  unsigned int Size; // edx
  Scaleform::GFx::AS3::Value *v78; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v80; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v81; // eax
  Scaleform::GFx::AS3::Value::V1U *v82; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v83; // edx
  Scaleform::GFx::AS3::Value::V1U v84; // eax
  Scaleform::StringDataPtr v85; // [esp-8h] [ebp-190h] BYREF
  unsigned int mn_index; // [esp+10h] [ebp-178h] BYREF
  unsigned int ccp; // [esp+14h] [ebp-174h] BYREF
  Scaleform::GFx::AS3::Value class_; // [esp+18h] [ebp-170h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+28h] [ebp-160h]
  const Scaleform::GFx::AS3::Traits *_2tr; // [esp+2Ch] [ebp-15Ch]
  Scaleform::GFx::AS3::CheckResult v91; // [esp+32h] [ebp-156h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [esp+33h] [ebp-155h] BYREF
  unsigned int slot_ind; // [esp+34h] [ebp-154h] BYREF
  Scaleform::GFx::AS3::TR::ReadMnObject args; // [esp+38h] [ebp-150h] BYREF
  Scaleform::GFx::AS3::Value v95; // [esp+78h] [ebp-110h] BYREF
  Scaleform::GFx::AS3::Value _1; // [esp+88h] [ebp-100h] BYREF
  Scaleform::GFx::AS3::Value _2; // [esp+98h] [ebp-F0h] BYREF
  Scaleform::GFx::AS3::VM::Error v98; // [esp+A8h] [ebp-E0h] BYREF
  Scaleform::GFx::AS3::TR::ReadArgsMnObject v99; // [esp+B0h] [ebp-D8h] BYREF
  Scaleform::StringDataPtr arg1; // [esp+180h] [ebp-8h] BYREF

  switch ( (unsigned int)opcode )
  {
    case 4u:
    case 0x66u:
      pCode = this->pCode;
      mn_index = *bcp;
      v43 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, &mn_index);
      pFile = this->CF->pFile;
      args.VMRef = pFile->VMRef;
      args.StateRef = st;
      args.Num = 0;
      args.File = pFile;
      Scaleform::GFx::AS3::Multiname::Multiname(
        &args.ArgMN,
        pFile,
        &pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v43]);
      v45 = Scaleform::GFx::AS3::TR::StackReader::Read(&args, &args.ArgMN);
      args.Num += v45;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        (Scaleform::GFx::AS3::Value *)&args.ArgObject);
      ++args.Num;
      if ( Scaleform::GFx::AS3::Tracer::EmitGetProperty(this, opcode, st, &args, v43) )
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
      v37 = this->pCode;
      mn_index = *bcp;
      v38 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v37, &mn_index);
      v39 = this->CF->pFile;
      VMRef = v39->VMRef;
      args.StateRef = st;
      args.VMRef = VMRef;
      args.Num = 0;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        (Scaleform::GFx::AS3::Value *)&args.ArgMN);
      ++args.Num;
      args.ArgMN.Name.value.VS._1.VInt = (int)v39;
      Scaleform::GFx::AS3::Multiname::Multiname(
        (Scaleform::GFx::AS3::Multiname *)&args.ArgObject,
        v39,
        &v39->File.pObject->Const_Pool.const_multiname.Data.Data[v38]);
      v41 = Scaleform::GFx::AS3::TR::StackReader::Read(&args, (Scaleform::GFx::AS3::Multiname *)&args.ArgObject);
      args.Num += v41;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        &v95);
      ++args.Num;
      if ( Scaleform::GFx::AS3::Tracer::EmitSetProperty(
             this,
             (const Scaleform::GFx::AS3::Traits *)opcode,
             (const Scaleform::GFx::AS3::TR::ReadValueMnObject *)&args,
             v38) )
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
      v56 = this->pCode;
      mn_index = *bcp;
      v57 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v56, &mn_index);
      v58 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &mn_index);
      v59 = this->CF->pFile;
      Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v99, v59->VMRef, st, v58);
      v99.File = v59;
      Scaleform::GFx::AS3::Multiname::Multiname(
        &v99.ArgMN,
        v59,
        &v59->File.pObject->Const_Pool.const_multiname.Data.Data[v57]);
      v60 = Scaleform::GFx::AS3::TR::StackReader::Read(&v99, &v99.ArgMN);
      v99.Num += v60;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        (Scaleform::GFx::AS3::Value *)&v99.ArgObject);
      ++v99.Num;
      if ( !Scaleform::GFx::AS3::Tracer::EmitCall(this, (Scaleform::GFx::AS3::Abc::Code::OpCode)opcode, st, &v99, v57) )
        goto LABEL_78;
      v85.Size = mn_index;
      v85.pStr = (const char *)bcp;
      goto LABEL_66;
    case 0x4Au:
      v61 = this->pCode;
      ccp = *bcp;
      v62 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v61, &ccp);
      v63 = this->pCode;
      mn_index = v62;
      v64 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v63, &ccp);
      v65 = this->CF->pFile;
      v66 = v64;
      Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v99, v65->VMRef, st, v64);
      v99.File = v65;
      Scaleform::GFx::AS3::Multiname::Multiname(
        &v99.ArgMN,
        v65,
        &v65->File.pObject->Const_Pool.const_multiname.Data.Data[mn_index]);
      v67 = Scaleform::GFx::AS3::TR::StackReader::Read(&v99, &v99.ArgMN);
      v99.Num += v67;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        (Scaleform::GFx::AS3::Value *)&v99.ArgObject);
      ++v99.Num;
      if ( Scaleform::GFx::AS3::Multiname::IsRunTime(&v99.ArgMN) )
        goto LABEL_79;
      if ( (v99.ArgObject.Flags & 0x400) != 0 )
      {
        if ( (v99.ArgObject.Flags & 0x1F) != 9 )
        {
          if ( (v99.ArgObject.Flags & 0x1F) == 0xD )
          {
            Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_construct, v66);
            v68 = *(Scaleform::GFx::AS3::Value::V1U *)(*(_DWORD *)(v99.ArgObject.value.VS._1.VInt + 20) + 100);
            class_.Bonus.pWeakProxy = 0;
            class_.value.VS._1 = v68;
            class_.Flags = 8;
LABEL_72:
            Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &st->OpStack.Data,
              &class_);
            Scaleform::GFx::AS3::Value::~Value(&class_);
            v85.Size = ccp;
            v85.pStr = (const char *)bcp;
LABEL_66:
            Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, (unsigned int *)v85.pStr, v85.Size);
            Scaleform::GFx::AS3::TR::ReadArgsMnObject::~ReadArgsMnObject(&v99);
            return 1;
          }
LABEL_79:
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_constructprop, mn_index, v66);
          pObject = this->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
          class_.Bonus.pWeakProxy = 0;
          class_.value.VS._1.VInt = (int)pObject;
          class_.Flags = 8;
          Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &st->OpStack.Data,
            &class_);
          Scaleform::GFx::AS3::Value::~Value(&class_);
          v85.Size = ccp;
          v85.pStr = (const char *)bcp;
          goto LABEL_66;
        }
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_construct, v66);
        class_.value.VS._1.VInt = *(_DWORD *)(v99.ArgObject.value.VS._1.VInt + 100);
        class_.Bonus.pWeakProxy = 0;
        class_.Flags = 8;
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &st->OpStack.Data,
          &class_);
        Scaleform::GFx::AS3::Value::~Value(&class_);
        Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
        Scaleform::GFx::AS3::TR::ReadArgsMnObject::~ReadArgsMnObject(&v99);
        return 1;
      }
      else
      {
        if ( v66 )
          goto LABEL_79;
        vm = this->CF->pFile->VMRef;
        _2tr = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &v99.ArgObject, 0);
        vm = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::AS3::FindFixedSlot(
                                          (const Scaleform::GFx::AS3::SlotInfo *)vm,
                                          _2tr,
                                          (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&v99.ArgMN,
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
               &v91,
               _2tr,
               (Scaleform::GFx::AS3::SlotInfo *)vm,
               &class_)->Result )
          goto LABEL_72;
        Scaleform::GFx::AS3::Value::~Value(&class_);
LABEL_78:
        Scaleform::GFx::AS3::TR::ReadArgsMnObject::~ReadArgsMnObject(&v99);
        return 0;
      }
    case 0x5Du:
      v46 = this->pCode;
      mn_index = *bcp;
      v47 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v46, &mn_index);
      v48 = this->pCode;
      v49 = v47;
      ccp = mn_index;
      v50 = (Scaleform::GFx::AS3::VM *)v48[mn_index];
      ccp = mn_index + 1;
      vm = v50;
      OrigValueConsumer = Scaleform::GFx::AS3::Tracer::GetOrigValueConsumer(this, mn_index);
      if ( vm == (Scaleform::GFx::AS3::VM *)102 )
      {
        Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &ccp);
        if ( Scaleform::GFx::AS3::Tracer::EmitFindProperty(this, st, v49, 1, OrigValueConsumer, 1) )
        {
          Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
          return 1;
        }
      }
      else if ( Scaleform::GFx::AS3::Tracer::EmitFindProperty(this, st, v49, 0, OrigValueConsumer, 1) )
      {
        goto LABEL_63;
      }
$LN954_0:
      v52 = this->pCode;
      mn_index = *bcp;
      v53 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v52, &mn_index);
      if ( !Scaleform::GFx::AS3::Tracer::EmitFindProperty(this, st, v53, 0, op_nop, 0) )
        return 0;
LABEL_63:
      Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, mn_index);
      return 1;
    case 0x5Eu:
      goto $LN954_0;
    case 0x60u:
      v54 = this->pCode;
      mn_index = *bcp;
      v55 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v54, &mn_index);
      if ( Scaleform::GFx::AS3::Tracer::EmitFindProperty(this, st, v55, 1, op_nop, 0) )
        goto LABEL_63;
      return 0;
    case 0x62u:
      v35 = this->pCode;
      mn_index = *bcp;
      v36 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v35, &mn_index);
      return Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(this, bcp, mn_index, st, v36);
    case 0x64u:
      v30 = this->pCode;
      ccp = *bcp;
      v31 = v30[ccp++];
      if ( v31 == 108 )
      {
        Scaleform::GFx::AS3::TR::State::exec_getglobalscope(st);
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getglobalslot);
        v32 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &ccp);
        Scaleform::GFx::AS3::TR::State::exec_getslot(st, v32);
        Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
        return 1;
      }
      if ( v31 != 43 )
        return 0;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        &this->OrigOpcodePos,
        &ccp);
      v33 = this->pCode[ccp++];
      if ( v33 == 109 )
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_setglobalslot);
        v34 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &ccp);
        Scaleform::GFx::AS3::TR::State::exec_getglobalscope(st);
        Scaleform::GFx::AS3::TR::State::SwapOp(st);
        Scaleform::GFx::AS3::TR::State::exec_setslot(st, v34);
        Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
        return 1;
      }
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy>>::PopBack(
        &this->OrigOpcodePos,
        1u);
      return 0;
    case 0x70u:
      Size = st->OpStack.Data.Size;
      v78 = &st->OpStack.Data.Data[Size - 1];
      if ( ((v78->Flags & 0x1F) - 12 > 3 || v78->value.VS._1.VInt)
        && !Scaleform::GFx::AS3::Tracer::IsStringType(this, &st->OpStack.Data.Data[Size - 1]) )
      {
        return 0;
      }
      Scaleform::GFx::AS3::TR::State::ConvertOpTo(
        st,
        this->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject,
        NullOrNot);
      v76 = bcp;
      v85.Size = *bcp;
      goto LABEL_98;
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
      if ( !IsSIntType )
        return 0;
      v76 = bcp;
      v85.Size = *bcp;
      goto LABEL_98;
    case 0x76u:
      if ( !Scaleform::GFx::AS3::Tracer::IsBooleanType(this, &st->OpStack.Data.Data[st->OpStack.Data.Size - 1]) )
        return 0;
      v76 = bcp;
      v85.Size = *bcp;
LABEL_98:
      Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, v76, v85.Size);
      return 1;
    case 0x80u:
      v12 = this->pCode;
      ccp = *bcp;
      v13 = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v12, &ccp);
      v14 = this->CF->pFile;
      v15 = v14->File.pObject;
      vm = v13;
      v16 = &v15->Const_Pool.const_multiname.Data.Data[(_DWORD)v13];
      v17 = &st->OpStack.Data.Data[st->OpStack.Data.Size - 1];
      v18 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v14->VMRef, v14, v16);
      v19 = v18;
      if ( v18 )
      {
        v24 = (char *)v18->ITraits.pObject;
        v25 = v17->Flags & 0x1F;
        mn_index = v25;
        if ( !v25 && v24 != (char *)this->CF->pFile->VMRef->TraitsClassClass.pObject->ITraits.pObject )
        {
          if ( !Scaleform::GFx::AS3::Tracer::IsNotObjectType(this, (Scaleform::GFx::AS3::InstanceTraits::Traits *)v24)
            && Scaleform::GFx::AS3::Tracer::GetNewTopOpCode(this, 0) == 33 )
          {
            WCode = this->WCode;
            v27 = WCode->Data.Size;
            Data = WCode->Data.Data;
            v85.Size = 1;
            v85.pStr = v24;
            Data[v27 - 1] = 32;
            Scaleform::GFx::AS3::TR::State::ConvertOpTo(
              st,
              (Scaleform::GFx::AS3::InstanceTraits::Traits *)v85.pStr,
              (Scaleform::GFx::AS3::Value::TraceNullType)v85.Size);
            Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
            return 1;
          }
          v25 = mn_index;
        }
        if ( v25 - 12 <= 3 && !v17->value.VS._1.VInt || Scaleform::GFx::AS3::Tracer::ValueIsOfType(this, v17, v19) )
        {
          CanBeNull = Scaleform::GFx::AS3::Tracer::CanBeNull(
                        this,
                        (const Scaleform::GFx::AS3::InstanceTraits::Traits *)v24);
          if ( (v17->Flags & 0x1F) - 12 <= 3 && !v17->value.VS._1.VInt )
            CanBeNull = Null;
          Scaleform::GFx::AS3::TR::State::ConvertOpTo(st, (Scaleform::GFx::AS3::InstanceTraits::Traits *)v24, CanBeNull);
          Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
          return 1;
        }
        else
        {
          Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, ccp);
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_coerce, (unsigned int)vm);
          Scaleform::GFx::AS3::TR::State::ConvertOpTo(st, (Scaleform::GFx::AS3::InstanceTraits::Traits *)v24, NullOrNot);
          return 1;
        }
      }
      else
      {
        Name = Scaleform::GFx::AS3::Abc::Multiname::GetName(v16, &arg1, &this->CF->pFile->File.pObject->Const_Pool);
        v21 = this->CF->pFile->VMRef;
        Scaleform::StringDataPtr::StringDataPtr(&v85, Name->pStr);
        Scaleform::GFx::AS3::VM::Error::Error(&v98, eClassNotFoundError, (Scaleform::String)v21, v85);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v21,
          v22,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
        pNode = v98.Message.pNode;
        --v98.Message.pNode->RefCount;
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
      v72 = st->OpStack.Data.Size;
      Flags = p_OpStack->Data.Data[v72 - 1].Flags;
      v74 = &p_OpStack->Data.Data[v72 - 1];
      if ( ((Flags & 0x1F) - 12 > 3 || v74->value.VS._1.VInt)
        && !Scaleform::GFx::AS3::Tracer::ValueIsOfType(this, v74, ITr) )
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
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        &_2);
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        &st->OpStack,
        &_1);
      ValueTraits = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &_1, 0);
      v80 = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &_2, 0);
      v81 = this->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject;
      _2tr = v80;
      if ( ValueTraits == v81 || v80 == v81 )
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_add);
        v82 = (Scaleform::GFx::AS3::Value::V1U *)this->CF->pFile->VMRef->TraitsString.pObject;
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
              v83 = this->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject;
              class_.Bonus.pWeakProxy = 0;
              class_.value.VS._1.VInt = (int)v83;
              class_.Flags = 8;
              v85.Size = (unsigned int)&class_;
              goto LABEL_125;
            }
            Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_add);
            if ( !Scaleform::GFx::AS3::Tracer::IsPrimitiveType(this, ValueTraits)
              || !Scaleform::GFx::AS3::Tracer::IsPrimitiveType(
                    this,
                    (Scaleform::GFx::AS3::InstanceTraits::Traits *)_2tr) )
            {
              v82 = (Scaleform::GFx::AS3::Value::V1U *)this->CF->pFile->VMRef->TraitsObject.pObject;
              class_.Bonus.pWeakProxy = 0;
              class_.Flags = 72;
              goto LABEL_124;
            }
          }
          v82 = (Scaleform::GFx::AS3::Value::V1U *)this->CF->pFile->VMRef->TraitsNumber.pObject;
          class_.Bonus.pWeakProxy = 0;
          class_.Flags = 8;
          goto LABEL_124;
        }
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_add_td);
        v82 = (Scaleform::GFx::AS3::Value::V1U *)this->CF->pFile->VMRef->TraitsNumber.pObject;
        class_.Flags = 8;
      }
      class_.Bonus.pWeakProxy = 0;
LABEL_124:
      v84 = v82[25];
      v85.Size = (unsigned int)&class_;
      class_.value.VS._1 = v84;
LABEL_125:
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &st->OpStack.Data,
        (Scaleform::GFx::AS3::Value *)v85.Size);
      Scaleform::GFx::AS3::Value::~Value(&class_);
      Scaleform::GFx::AS3::Value::~Value(&_1);
      Scaleform::GFx::AS3::Value::~Value(&_2);
      return 1;
    case 0xD0u:
      return Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(this, bcp, *bcp, st, Traits_Unknown);
    case 0xD1u:
      return Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(this, bcp, *bcp, st, Traits_Boolean);
    case 0xD2u:
      v85.Size = 2;
      return Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(
               this,
               bcp,
               *bcp,
               st,
               (Scaleform::GFx::AS3::BuiltinTraitsType)v85.Size);
    case 0xD3u:
      v85.Size = 3;
      return Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(
               this,
               bcp,
               *bcp,
               st,
               (Scaleform::GFx::AS3::BuiltinTraitsType)v85.Size);
    default:
      return 0;
  }
}
