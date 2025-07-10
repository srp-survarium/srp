void __thiscall Scaleform::GFx::AS3::TR::State::exec_if(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int *bcp,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // esi
  Scaleform::GFx::AS3::Tracer *pTracer; // edi
  Scaleform::GFx::AS3::Abc::Code::OpCode v6; // eax
  int v7; // ebp

  p_OpStack = &this->OpStack;
  pTracer = this->pTracer;
  if ( Scaleform::GFx::AS3::Tracer::IsSIntType(this->pTracer, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1])
    && Scaleform::GFx::AS3::Tracer::IsSIntType(pTracer, &p_OpStack->Data.Data[this->OpStack.Data.Size - 2]) )
  {
    v6 = opcode;
    switch ( opcode )
    {
      case op_ifnlt:
        v6 = op_ifnlt_ti;
        break;
      case op_ifnle:
        v6 = op_ifnle_ti;
        break;
      case op_ifngt:
        v6 = op_ifngt_ti;
        break;
      case op_ifnge:
        v6 = op_ifnge_ti;
        break;
      case op_ifeq:
      case op_ifstricteq:
        v6 = op_ifeq_ti;
        break;
      case op_ifne:
      case op_ifstrictne:
        v6 = op_ifne_ti;
        break;
      case op_iflt:
        v6 = op_iflt_ti;
        break;
      case op_ifle:
        v6 = op_ifle_ti;
        break;
      case op_ifgt:
        v6 = op_ifgt_ti;
        break;
      case op_ifge:
        v6 = op_ifge_ti;
        break;
      default:
        break;
    }
LABEL_27:
    pTracer->WCode->Data.Data[pTracer->WCode->Data.Size - 1] = v6;
    goto LABEL_28;
  }
  if ( Scaleform::GFx::AS3::Tracer::IsNumberType(pTracer, &p_OpStack->Data.Data[p_OpStack->Data.Size - 1])
    && Scaleform::GFx::AS3::Tracer::IsNumberType(pTracer, &p_OpStack->Data.Data[this->OpStack.Data.Size - 2]) )
  {
    v6 = opcode;
    switch ( opcode )
    {
      case op_ifnlt:
        v6 = op_ifnlt_td;
        break;
      case op_ifnle:
        v6 = op_ifnle_td;
        break;
      case op_ifngt:
        v6 = op_ifngt_td;
        break;
      case op_ifnge:
        v6 = op_ifnge_td;
        break;
      case op_ifeq:
      case op_ifstricteq:
        v6 = op_ifeq_td;
        break;
      case op_ifne:
      case op_ifstrictne:
        v6 = op_ifne_td;
        break;
      case op_iflt:
        v6 = op_iflt_td;
        break;
      case op_ifle:
        v6 = op_ifle_td;
        break;
      case op_ifgt:
        v6 = op_ifgt_td;
        break;
      case op_ifge:
        v6 = op_ifge_td;
        break;
      default:
        goto LABEL_27;
    }
    goto LABEL_27;
  }
LABEL_28:
  v7 = Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(pTracer->pCode, bcp);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &p_OpStack->Data,
    p_OpStack->Data.Size - 1);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &p_OpStack->Data,
    p_OpStack->Data.Size - 1);
  Scaleform::GFx::AS3::Tracer::StoreOffset(pTracer, *bcp, this, v7, -1);
}
