void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain,1,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *, Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain,1,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)((char *)_this + dword_AAE9DC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain,2,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain,2,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)(dword_AAE9AC + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Array,1,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Array *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Array,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Array *)(dword_AAD75C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,1,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,1,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADDFC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,3,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,3,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADD7C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,5,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,5,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADEAC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,7,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,7,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADE44 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,9,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,9,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADD84 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,17,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,17,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADE8C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,19,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,19,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADF1C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,21,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,21,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADE3C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,23,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,23,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)((char *)_this + dword_AADE24),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,11,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,11,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADF3C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,13,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,13,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v6.VInt + dword_AADE34),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,15,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,15,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADF0C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_display::BitmapDataTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)(dword_AAE0C4 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)((char *)_this + dword_AAE6DC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,5,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,5,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)(v6.VInt + dword_AAE4F4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,7,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_display::BitmapDataTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,7,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)(dword_AAE8BC + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,1,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,1,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *)(dword_AADF5C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,3,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,3,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *)(dword_AADE6C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,5,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,5,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *)(dword_AADF84 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_utils::ByteArray,0,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_utils::ByteArray,0,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_utils::ByteArray *)(dword_AAC2D4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)((char *)_this + dword_AAC2FC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,4,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,4,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC39C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,6,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,6,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC38C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,8,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,8,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC32C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,26,Scaleform::GFx::ASString,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,unsigned long> args; // [esp+8h] [ebp-10h] BYREF

  args.Result = result;
  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, Scaleform::GFx::ASString *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,26,Scaleform::GFx::ASString,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC28C + v6.VInt),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,29,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,29,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(v6.VInt + dword_AAC2F4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,30,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,30,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC374 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,32,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,32,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC214 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,33,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,33,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC33C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,34,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,34,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC234 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,36,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,36,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC2B4 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,37,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,37,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC344 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,38,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,38,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC264 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,39,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,39,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)((char *)_this + dword_AAC34C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC304 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,1,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *)(dword_AAC874 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::ColorTransformTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *)(dword_AACA74 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Array *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl::Array *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl::ArrayTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl::Array *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl::Array *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Array *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *)(dword_AAE064 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Date,0,double,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  double v9; // st7
  bool v11; // zf
  Scaleform::GFx::AS3::Value *v12; // eax
  unsigned int v13; // edx
  Scaleform::GFx::AS3::Value::Extra v14; // ecx
  Scaleform::GFx::AS3::Value *v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // edx
  Scaleform::GFx::AS3::Value::Extra v18; // ecx
  Scaleform::GFx::AS3::Value v19; // [esp+8h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<double,Scaleform::GFx::AS3::Value const &> args; // [esp+28h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v19 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v19.Flags;
  }
  def_ags._0.value.VNumber = v19.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v19.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v19);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v19);
    LOWORD(Flags) = v19.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v19);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v19);
  }
  args.Vm = vm;
  args.Result = result;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  args.r = v9;
  if ( !argc )
    argv = &def_ags;
  v11 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v11 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Date *, long double *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Date,0,double,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Date *)(v6.VInt + dword_AAD64C),
      &args.r,
      &argv->_0);
    if ( !args.Vm->HandleException )
    {
      v15 = args.Result;
      v16 = args.Result->Flags;
      *(double *)&v19.Flags = args.r;
      v17 = v19.Flags;
      args.Result->Flags = v16 & 0xFFFFFFE0 | 4;
      v18.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v19.Bonus;
      v15->value.VS._1.VInt = v17;
      v15->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v18.pWeakProxy;
    }
    if ( (def_ags._0.Flags & 0x1F) > 9 )
    {
      if ( (def_ags._0.Flags & 0x200) != 0 )
        goto LABEL_22;
LABEL_27:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
    }
  }
  else
  {
    if ( !args.Vm->HandleException )
    {
      v12 = args.Result;
      *(double *)&v19.Flags = v9;
      v13 = v19.Flags;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      v14.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v19.Bonus;
      v12->value.VS._1.VInt = v13;
      v12->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v14.pWeakProxy;
    }
    if ( (def_ags._0.Flags & 0x1F) > 9 )
    {
      if ( (def_ags._0.Flags & 0x200) != 0 )
      {
LABEL_22:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
        return;
      }
      goto LABEL_27;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,1,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,1,double,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(v6.VInt + dword_AAD4A4),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,42,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,42,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD0B4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,44,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,44,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD2CC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,46,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,46,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD494 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,48,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,48,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD0BC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,50,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,50,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD6A4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,52,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,52,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD40C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,54,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,54,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD58C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,56,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,56,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD7AC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,58,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,58,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD734 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,60,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,60,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD014 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,62,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,62,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD3DC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,64,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,64,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD6D4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,66,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,66,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD1E4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,68,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,68,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD41C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,70,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,70,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD11C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,3,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,3,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE474 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)_this + dword_AAE204),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,7,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,7,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v6.VInt + dword_AAE5CC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Array *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl::Array *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl::ArrayTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl::Array *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl::Array *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Array *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE524 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,18,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,18,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)_this + dword_AAE2B4),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,20,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,20,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE74C + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,24,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,24,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE3F4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,26,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,26,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE1DC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,28,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,28,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE2A4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,30,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,30,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE344 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,34,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,34,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE744 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,36,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,36,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE7FC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,38,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,38,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE6CC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,45,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,45,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v6.VInt + dword_AAE5EC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,47,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,47,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE784 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,49,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,49,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE584 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,51,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,51,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE0EC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,53,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,53,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE174 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,58,bool,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *> args; // [esp+1Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_display::DisplayObjectTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, bool *, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,58,bool,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE8AC + v6.VInt),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(to.Flags) = r;
    Flags = to.Flags;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = Flags;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,11,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,11,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE3B4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,14,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_display::DisplayObjectTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,14,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE7EC + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,1,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,1,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *)(v6.VInt + dword_AAE3BC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,4,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,4,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *)(v6.VInt + dword_AAE554),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_system::Domain,1,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_system::Domain *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_system::Domain *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_system::Domain *, Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_system::Domain,1,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_system::Domain *)((char *)_this + dword_AAEA6C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_system::Domain,2,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_system::Domain *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_system::Domain,2,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_system::Domain *)(dword_AAEA34 + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,1,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,1,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADEDC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,3,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,3,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADFAC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,5,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,5,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADE84 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,7,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,7,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADDC4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,9,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,9,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADDF4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,17,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,17,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v6.VInt + dword_AADF4C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,19,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,19,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADDCC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,21,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,21,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADFB4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,11,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,11,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADF94 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,13,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,13,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v6.VInt + dword_AADEA4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,15,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,15,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v6.VInt + dword_AADFA4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Error,0,Scaleform::GFx::ASString,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,long> args; // [esp+8h] [ebp-10h] BYREF

  args.Result = result;
  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Error *, Scaleform::GFx::ASString *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Error,0,Scaleform::GFx::ASString,long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Error *)(dword_AAD684 + v6.VInt),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,1,bool,Scaleform::GFx::AS3::Instances::fl_events::Event *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Instances::fl_events::Event *> args; // [esp+1Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_events::EventTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *, bool *, Scaleform::GFx::AS3::Instances::fl_events::Event *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,1,bool,Scaleform::GFx::AS3::Instances::fl_events::Event *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)(dword_AADC6C + v6.VInt),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(to.Flags) = r;
    Flags = to.Flags;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = Flags;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,2,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,2,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)(dword_AADA3C + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,4,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,4,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)(dword_AAD9C4 + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,2,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,2,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(v6.VInt + dword_AAEBB4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,7,Scaleform::GFx::ASString,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,unsigned long> args; // [esp+8h] [ebp-10h] BYREF

  args.Result = result;
  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, Scaleform::GFx::ASString *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,7,Scaleform::GFx::ASString,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(dword_AAEB7C + v6.VInt),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,0,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,0,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(v6.VInt + dword_AAEBEC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,2,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,2,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *)(v6.VInt + dword_AAE074),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)((char *)_this + dword_AADB74),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,3,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,3,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)(dword_AADB7C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,7,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,7,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)(v6.VInt + dword_AADCCC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,2,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,2,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(v6.VInt + dword_AAEBDC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,0,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,0,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(v6.VInt + dword_AAEBCC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,12,unsigned long,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<unsigned long,unsigned long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, unsigned int *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,12,unsigned long,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(v6.VInt + dword_AAEB4C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 3;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,13,unsigned long,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<unsigned long,unsigned long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, unsigned int *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,13,unsigned long,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(v6.VInt + dword_AAEBC4),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 3;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_text::Font,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Class *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Class *VClass; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VClass = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::ClassClassTI, &to, argv);
    VClass = to.value.VS._1.VClass;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_text::Font *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Class *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_text::Font,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Class *>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_text::Font *)(dword_AACD5C + v6.VInt),
      result,
      VClass);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::Font,3,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::Font *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::Font,3,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::Font *)(dword_AACFE4 + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,1,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(dword_AAED4C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,3,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,3,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(dword_AAED14 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,5,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,5,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(dword_AAECD4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,7,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,7,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(dword_AAECA4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,1,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,1,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v6.VInt + dword_AADB5C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,3,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,3,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v6.VInt + dword_AAD8B4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,5,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,5,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v6.VInt + dword_AAD91C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,7,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,7,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v6.VInt + dword_AADD6C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,9,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,9,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_AAD8E4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,11,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,11,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_AADD54 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,13,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,13,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)((char *)_this + dword_AADBD4),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,15,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,15,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v6.VInt + dword_AADB0C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,46,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,46,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)((char *)_this + dword_AAD594),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,47,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,47,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)((char *)_this + dword_AAD764),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,48,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,48,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)((char *)_this + dword_AAD304),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,49,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,49,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)((char *)_this + dword_AAD634),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,50,bool,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v8; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, bool *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,50,bool,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(v6.VInt + dword_AAD5B4),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v8.VS._1.VBool = r;
      args.Result->value = v8;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,51,bool,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v8; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, bool *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,51,bool,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(v6.VInt + dword_AAD414),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v8.VS._1.VBool = r;
      args.Result->value = v8;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,53,double,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Value::V1U _this; // [esp+10h] [ebp-20h]
  long double _thisa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = v6;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, long double *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,53,double,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(dword_AAD064 + _this.VInt),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
  {
    _thisa = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
    args.Result->value.VNumber = _thisa;
  }
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,56,bool,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  bool v10; // zf
  Scaleform::GFx::AS3::Value *v11; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::Extra v13; // edx
  Scaleform::GFx::AS3::Value v14; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Value const &> args; // [esp+28h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v14 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v14.Flags;
  }
  def_ags._0.value.VNumber = v14.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v14.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v14);
    LOWORD(Flags) = v14.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
  }
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  if ( !argc )
    argv = &def_ags;
  v10 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v10 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, bool *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,56,bool,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(dword_AAD754 + v6.VInt),
      &args.r,
      &argv->_0);
    if ( !args.Vm->HandleException )
    {
      v11 = args.Result;
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v13.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v14.Bonus;
      LOBYTE(v14.Flags) = r;
      v11->value.VS._1.VInt = v14.Flags;
      v11->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v13.pWeakProxy;
    }
  }
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,79,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,79,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(dword_AAD3FC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,80,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,80,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(dword_AAD1FC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,82,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,82,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)((char *)_this + dword_AAD624),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,83,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,83,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)((char *)_this + dword_AAD74C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,84,Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  bool v10; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value v12; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const &> args; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+28h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v12 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v12.Flags;
  }
  def_ags._0.value.VNumber = v12.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v12.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v12);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v12);
    LOWORD(Flags) = v12.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v12);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v12);
  }
  args.Vm = vm;
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  if ( !argc )
    argv = &def_ags;
  v10 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v10 )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, Scaleform::GFx::ASString *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,84,Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(dword_AAD63C + v6.VInt),
      &args.r,
      &argv->_0);
  if ( !args.Vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,85,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,85,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(dword_AAD784 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,89,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,89,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)((char *)_this + dword_AAD51C),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,1,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,1,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_AADDD4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,3,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,3,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_AADFC4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,5,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,5,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_AADF24 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,7,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,7,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_AADEBC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,9,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,9,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(v6.VInt + dword_AADE5C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,11,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,11,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(v6.VInt + dword_AADFBC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,13,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,13,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_AADD94 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,15,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,15,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_AADF64 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::IME,3,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::IME *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::IME,3,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_system::IME *)(v6.VInt + dword_AAEA24),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::IME,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Classes::fl_system::IME *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Classes::fl_system::IME *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::IME *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::IME,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_system::IME *)((char *)_this + dword_AAEA1C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::IME,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Classes::fl_system::IME *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Classes::fl_system::IME *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::IME *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::IME,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_system::IME *)((char *)_this + dword_AAEB14),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(dword_AAE49C + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,3,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,3,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(v6.VInt + dword_AAE4E4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(dword_AAE3D4 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,7,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,7,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(v6.VInt + dword_AAE98C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,9,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,9,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(v6.VInt + dword_AAE704),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,11,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,11,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(dword_AAE494 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *)((char *)_this + dword_AADB6C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,1,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,1,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(v6.VInt + dword_AADBAC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,3,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,3,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AADA9C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,5,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,5,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(v6.VInt + dword_AADBCC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,7,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,7,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(v6.VInt + dword_AAD80C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,9,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,9,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(v6.VInt + dword_AADD14),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,11,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,11,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AADD04 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,13,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,13,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AADA74 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,15,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,15,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(v6.VInt + dword_AADA94),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Loader,6,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 1;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Loader *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Loader,6,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Loader *)(v6.VInt + dword_AAE834),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,7,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,7,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE544 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,17,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,17,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE4C4 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,1,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,1,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD654),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,2,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,2,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD37C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,3,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,3,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD22C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,5,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,5,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD0CC),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,6,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,6,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD1EC),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,7,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,7,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD67C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,8,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,8,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD4EC),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,9,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,9,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD324),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,10,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,10,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD434),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,0,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,0,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD7CC),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,11,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,11,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD054),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,12,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,12,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD16C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,13,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,13,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD46C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::Vector3DTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)(dword_AAC9D4 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::Matrix3DTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)(dword_AACA6C + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,17,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::Matrix3DTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,17,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)(dword_AAC7BC + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::MatrixTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Matrix *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)(dword_AACA64 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,7,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,7,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)(dword_AAC784 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Classes::fl_ui::Mouse *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Classes::fl_ui::Mouse *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Mouse *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_ui::Mouse *)((char *)_this + dword_AAE05C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,1,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,1,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v6.VInt + dword_AAD7E4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,3,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,3,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v6.VInt + dword_AAD84C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,6,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,6,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v6.VInt + dword_AADAEC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,8,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,8,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v6.VInt + dword_AAD804),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,10,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,10,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v6.VInt + dword_AADC14),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,16,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,16,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AADAC4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,20,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,20,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v6.VInt + dword_AADA84),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,12,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,12,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AAD89C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,14,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,14,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AADA8C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,6,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,6,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(v6.VInt + dword_AAE5DC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,11,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,11,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(v6.VInt + dword_AAE3DC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *)((char *)_this + dword_AAE03C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_AAC4FC + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,4,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,4,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_AAC584 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,6,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,6,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_AAC6A4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,8,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::NetConnection *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,8,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)((char *)_this + dword_AAC6CC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *)(dword_AADCF4 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection,3,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection,3,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *)(dword_AAC75C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection,5,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection,5,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *)(dword_AAC6DC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Point,3,bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *> args; // [esp+1Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::PointTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Point *, bool *, Scaleform::GFx::AS3::Instances::fl_geom::Point *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Point,3,bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(dword_AAC714 + v6.VInt),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(to.Flags) = r;
    Flags = to.Flags;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = Flags;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Point,4,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Point *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Point,4,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(dword_AAC944 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,1,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,1,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *)(dword_AADC24 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,3,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,3,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *)(dword_AAD9A4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,1,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,1,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *)(dword_AADC04 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,3,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,3,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *)(dword_AADB24 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,1,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,1,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC7EC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Point *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::PointTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Point *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AACA34 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,5,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,5,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC8F4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,7,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,7,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC924 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Point *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::PointTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Point *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC98C + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,16,bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *> args; // [esp+1Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::PointTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, bool *, Scaleform::GFx::AS3::Instances::fl_geom::Point *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,16,bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC79C + v6.VInt),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(to.Flags) = r;
    Flags = to.Flags;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = Flags;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,17,bool,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *> args; // [esp+1Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::RectangleTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, bool *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,17,bool,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC72C + v6.VInt),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(to.Flags) = r;
    Flags = to.Flags;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = Flags;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,18,bool,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *> args; // [esp+1Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::RectangleTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, bool *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,18,bool,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC8E4 + v6.VInt),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(to.Flags) = r;
    Flags = to.Flags;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = Flags;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,20,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Point *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::PointTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Point *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,20,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC864 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,22,bool,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *> args; // [esp+1Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::RectangleTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, bool *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,22,bool,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC8CC + v6.VInt),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(to.Flags) = r;
    Flags = to.Flags;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = Flags;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,25,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Point *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::PointTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Point *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,25,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC794 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,11,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,11,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC8AC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,13,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Point *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::PointTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Point *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,13,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC6E4 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::RegExp,5,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::RegExp,5,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_AAD504 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::RegExp,9,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::RegExp,9,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_AAD06C + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::SharedObject *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_AAC6B4 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,3,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::SharedObject *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,3,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_AAC44C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,4,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::SharedObject *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,4,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_AAC484 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,6,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::SharedObject *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,6,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_AAC3CC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,11,Scaleform::GFx::ASString,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,long> args; // [esp+8h] [ebp-10h] BYREF

  args.Result = result;
  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::SharedObject *, Scaleform::GFx::ASString *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,11,Scaleform::GFx::ASString,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_AAC40C + v6.VInt),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,13,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::SharedObject *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,13,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)((char *)_this + dword_AAC5FC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,3,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,3,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *)(v6.VInt + dword_AAE154),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,11,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,11,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *)(v6.VInt + dword_AAE0D4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,15,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,15,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *)(v6.VInt + dword_AAE60C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,4,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::Socket *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,4,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)((char *)_this + dword_AAC654),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,8,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,8,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC3E4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,29,Scaleform::GFx::ASString,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,unsigned long> args; // [esp+8h] [ebp-10h] BYREF

  args.Result = result;
  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, Scaleform::GFx::ASString *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,29,Scaleform::GFx::ASString,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC57C + v6.VInt),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,30,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,30,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(v6.VInt + dword_AAC49C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,31,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,31,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC68C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,33,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,33,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC624 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,34,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,34,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC664 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,35,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,35,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC52C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,37,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,37,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC414 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,38,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,38,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC5A4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,39,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,39,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC59C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::Socket *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)((char *)_this + dword_AAC6BC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,41,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::Socket *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,41,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)((char *)_this + dword_AAC4D4),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,12,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,12,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC5EC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,1,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,1,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(dword_AACB84 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,3,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,3,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(dword_AACACC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,5,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,5,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(dword_AACB34 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,7,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,7,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(dword_AACB9C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,9,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,9,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(dword_AACB14 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,11,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,11,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(dword_AACADC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Sprite,1,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Sprite *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Sprite,1,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)(v6.VInt + dword_AAE944),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Sprite,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::Sprite *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::Sprite *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_display::SpriteTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Sprite *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_display::Sprite *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Sprite,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::Sprite *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)(dword_AAE7AC + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Sprite,9,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Sprite *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Sprite,9,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)(v6.VInt + dword_AAE624),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Sprite,13,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Sprite *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Sprite,13,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)(dword_AAE80C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Stage *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)((char *)_this + dword_AAE6B4),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Stage *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)((char *)_this + dword_AAE244),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,9,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,9,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE97C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,17,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,17,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(v6.VInt + dword_AAE75C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,22,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Stage *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,22,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)((char *)_this + dword_AAE5A4),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,24,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Stage *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,24,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)((char *)_this + dword_AAE804),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,26,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,26,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(v6.VInt + dword_AAE6AC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,28,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,28,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(v6.VInt + dword_AAE0DC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,30,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,30,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE514 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,32,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,32,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE96C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,34,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,34,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(v6.VInt + dword_AAE454),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,37,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,37,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE0CC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,42,bool,Scaleform::GFx::AS3::Instances::fl_events::Event *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Instances::fl_events::Event *> args; // [esp+1Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_events::EventTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *, Scaleform::GFx::AS3::Instances::fl_events::Event *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,42,bool,Scaleform::GFx::AS3::Instances::fl_events::Event *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE684 + v6.VInt),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(to.Flags) = r;
    Flags = to.Flags;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = Flags;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,43,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,43,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE62C + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,49,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Stage *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,49,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)((char *)_this + dword_AAE794),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,51,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,51,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE63C + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,15,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Stage,15,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE11C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *)((char *)_this + dword_AACE84),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::System,2,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::System *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::System,2,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_system::System *)(dword_AAEAD4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::System,6,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Classes::fl_system::System *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Classes::fl_system::System *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::System *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::System,6,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_system::System *)((char *)_this + dword_AAEA44),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,2,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,2,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *)(dword_AAEB6C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,6,Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  bool v10; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value v12; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const &> args; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+28h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v12 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v12.Flags;
  }
  def_ags._0.value.VNumber = v12.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v12.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v12);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v12);
    LOWORD(Flags) = v12.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v12);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v12);
  }
  args.Vm = vm;
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  if ( !argc )
    argv = &def_ags;
  v10 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v10 )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *, Scaleform::GFx::ASString *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,6,Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *)(dword_AAED44 + v6.VInt),
      &args.r,
      &argv->_0);
  if ( !args.Vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,0,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,0,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *)(v6.VInt + dword_AAEC9C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)((char *)_this + dword_AADA1C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,1,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,1,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACF14),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextField *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)((char *)_this + dword_AACD9C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextField *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)((char *)_this + dword_AACDF4),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,7,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,7,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACC14),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,9,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,9,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACDB4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,17,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,17,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACF84),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,20,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextFormat *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_text::TextFormatTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_text::TextFormat *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,20,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextFormat *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACF24 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,22,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,22,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACD94),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,24,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,24,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACD6C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,26,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextField *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,26,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)((char *)_this + dword_AACDD4),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,28,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextField *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,28,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)((char *)_this + dword_AACCFC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,31,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,31,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACBE4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,35,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,35,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACD74),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,37,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,37,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACBDC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextField *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)((char *)_this + dword_AACFBC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,42,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,42,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACDA4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,44,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,44,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACE0C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,46,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,46,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACD24),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,50,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,50,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACBFC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,52,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_text::StyleSheetTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,52,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACCAC + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,54,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextField *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,54,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)((char *)_this + dword_AACEAC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,56,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,56,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACD84 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,60,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,60,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACEE4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,62,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextField *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,62,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)((char *)_this + dword_AACD3C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,64,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,64,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACD64),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,66,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,66,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACDCC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,67,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextField *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,67,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)((char *)_this + dword_AACBC4),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,70,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<long,long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,70,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACC2C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 2;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,73,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<long,long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,73,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACF04),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 2;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,74,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<long,long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,74,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACE44),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 2;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,76,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<long,long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,76,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACE2C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 2;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,77,Scaleform::GFx::ASString,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,long> args; // [esp+8h] [ebp-10h] BYREF

  args.Result = result;
  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, Scaleform::GFx::ASString *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,77,Scaleform::GFx::ASString,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACCE4 + v6.VInt),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,78,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<long,long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,78,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACC1C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 2;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,80,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextField *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,80,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)((char *)_this + dword_AACBEC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,11,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,11,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_AACD2C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,13,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,13,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACCD4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,9,bool,Scaleform::GFx::AS3::Instances::fl_text::TextField *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Instances::fl_text::TextField *> args; // [esp+1Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_text::TextFieldTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *, bool *, Scaleform::GFx::AS3::Instances::fl_text::TextField *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,9,bool,Scaleform::GFx::AS3::Instances::fl_text::TextField *>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *)(dword_AAEBE4 + v6.VInt),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(to.Flags) = r;
    Flags = to.Flags;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = Flags;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)((char *)_this + dword_AACFEC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACD8C + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACEEC + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,7,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,7,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACEFC + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACE54 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,17,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,17,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACC84 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,19,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,19,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACDAC + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,21,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,21,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACDFC + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,23,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,23,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACC3C + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,25,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,25,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACEB4 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,27,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,27,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACE34 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,29,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Array *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl::Array *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl::ArrayTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl::Array *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl::Array *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,29,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Array *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACF6C + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,31,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,31,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)((char *)_this + dword_AACC0C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,33,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,33,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACF34 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,35,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,35,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)((char *)_this + dword_AACE9C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,11,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,11,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)((char *)_this + dword_AACF2C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,13,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,13,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACE64 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,15,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,15,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACD1C + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,3,Scaleform::GFx::ASString,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,bool> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    args.a0 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, Scaleform::GFx::ASString *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,3,Scaleform::GFx::ASString,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *)(v6.VInt + dword_AACE5C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,7,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = (unsigned int)&vostok::memory::s_CRT_arena[5573944];
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,7,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *)(dword_AACC54 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::Timer,2,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::Timer,2,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_AAC27C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::Timer,4,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::Timer,4,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_AAC23C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,1,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,1,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v6.VInt + dword_AAD7F4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,3,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,3,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v6.VInt + dword_AADBF4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,5,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,5,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v6.VInt + dword_AAD83C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,7,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,7,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v6.VInt + dword_AADC94),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,9,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,9,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v6.VInt + dword_AADAAC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,17,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,17,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADA64 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,21,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,21,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v6.VInt + dword_AAD9BC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,23,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,23,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADB2C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,25,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,25,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AAD8C4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,29,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,29,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADA34 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,11,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,11,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v6.VInt + dword_AAD964),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,13,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,13,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AAD914 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,15,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,15,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADAF4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Transform,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::ColorTransformTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Transform,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Transform *)(dword_AACAC4 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Transform,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::MatrixTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Matrix *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Transform,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Transform *)(dword_AAC9C4 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Transform,7,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::Matrix3DTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Transform,7,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Transform *)(dword_AAC8EC + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,1,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,1,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)(dword_AADC4C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,3,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,3,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)(dword_AADB14 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,5,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,5,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)(dword_AADAE4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,7,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,7,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)(dword_AADA7C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,9,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,9,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)(dword_AAD93C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLLoader,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_net::URLRequest *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_net::URLRequestTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_net::URLRequest *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLLoader,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_net::URLRequest *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)(dword_AAC454 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,1,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,1,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(v6.VInt + dword_AAC62C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,3,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,3,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(v6.VInt + dword_AAC3AC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)((char *)_this + dword_AAC3DC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,7,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,7,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC60C + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)((char *)_this + dword_AAC474),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,17,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Array *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl::Array *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl::ArrayTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl::Array *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl::Array *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,17,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Array *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC614 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,19,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,19,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)((char *)_this + dword_AAC4AC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,21,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,21,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(v6.VInt + dword_AAC5AC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,23,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,23,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)((char *)_this + dword_AAC45C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,11,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,11,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(v6.VInt + dword_AAC434),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,13,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,13,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(v6.VInt + dword_AAC67C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,15,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,15,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)((char *)_this + dword_AAC65C),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLVariables,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::URLVariables *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::URLVariables *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLVariables,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::URLVariables *)((char *)_this + dword_AAC4BC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,2,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,2,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AAC84C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,4,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,4,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AACA44 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,6,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,6,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AACA24 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,8,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,8,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AAC9BC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,16,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::Vector3DTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,16,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AAC85C + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,21,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,21,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AAC82C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,13,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::Vector3DTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,13,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AAC804 + v6.VInt),
      result,
      VInt);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,14,double,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  unsigned int Flags; // ecx
  unsigned int v9; // edx
  Scaleform::GFx::AS3::Value to; // [esp+8h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<double,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::Vector3DTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double *, Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,14,double,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v6.VInt + dword_AAC9EC),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    Flags = args.Result->Flags;
    *(double *)&to.Flags = args.r;
    v9 = to.Flags;
    args.Result->Flags = Flags & 0xFFFFFFE0 | 4;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = v9;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,1,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(
      argv,
      (Scaleform::GFx::AS3::CheckResult *)&obj,
      (Scaleform::GFx::AS3::Value::V1U *)&args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(dword_AAF174 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,2,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,2,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(v6.VInt + dword_AAF08C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  _this = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)obj->value.VS._1.VInt;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      vm->StringManagerRef->pStringManager,
                      ",",
                      1u,
                      0);
  v7 = ConstStringNode;
  ++ConstStringNode->RefCount;
  v8 = ++ConstStringNode->RefCount == 1;
  --ConstStringNode->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = v7;
  ++v7->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)_this + dword_AAEFBC),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = v7->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,1,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(
      argv,
      (Scaleform::GFx::AS3::CheckResult *)&obj,
      (Scaleform::GFx::AS3::Value::V1U *)&args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_AAF01C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,2,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,2,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(v6.VInt + dword_AAF02C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  _this = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)obj->value.VS._1.VInt;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      vm->StringManagerRef->pStringManager,
                      ",",
                      1u,
                      0);
  v7 = ConstStringNode;
  ++ConstStringNode->RefCount;
  v8 = ++ConstStringNode->RefCount == 1;
  --ConstStringNode->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = v7;
  ++v7->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)((char *)_this + dword_AAEF1C),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = v7->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,1,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(
      argv,
      (Scaleform::GFx::AS3::CheckResult *)&obj,
      (Scaleform::GFx::AS3::Value::V1U *)&args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)(dword_AAF014 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,2,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,2,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)(v6.VInt + dword_AAF084),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  _this = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)obj->value.VS._1.VInt;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      vm->StringManagerRef->pStringManager,
                      ",",
                      1u,
                      0);
  v7 = ConstStringNode;
  ++ConstStringNode->RefCount;
  v8 = ++ConstStringNode->RefCount == 1;
  --ConstStringNode->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = v7;
  ++v7->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)_this + dword_AAEFFC),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = v7->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,1,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(
      argv,
      (Scaleform::GFx::AS3::CheckResult *)&obj,
      (Scaleform::GFx::AS3::Value::V1U *)&args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_AAF13C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,2,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,2,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(v6.VInt + dword_AAEF6C),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  _this = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)obj->value.VS._1.VInt;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      vm->StringManagerRef->pStringManager,
                      ",",
                      1u,
                      0);
  v7 = ConstStringNode;
  ++ConstStringNode->RefCount;
  v8 = ++ConstStringNode->RefCount == 1;
  --ConstStringNode->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = v7;
  ++v7->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)((char *)_this + dword_AAEF74),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = v7->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,1,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(
      argv,
      (Scaleform::GFx::AS3::CheckResult *)&obj,
      (Scaleform::GFx::AS3::Value::V1U *)&args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(dword_AAEF14 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,2,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,2,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(v6.VInt + dword_AAEED4),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  _this = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)obj->value.VS._1.VInt;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      vm->StringManagerRef->pStringManager,
                      ",",
                      1u,
                      0);
  v7 = ConstStringNode;
  ++ConstStringNode->RefCount;
  v8 = ++ConstStringNode->RefCount == 1;
  --ConstStringNode->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = v7;
  ++v7->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)_this + dword_AAEEA4),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = v7->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::XML,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Null; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Null = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
  Flags = Null->Flags;
  v10 = *Null;
  if ( (Null->Flags & 0x1F) > 9 )
  {
    if ( (Null->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Null);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Null);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::XML *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::XML,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::XML *)(dword_AAD2E4 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::XML,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Null; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Null = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
  Flags = Null->Flags;
  v10 = *Null;
  if ( (Null->Flags & 0x1F) > 9 )
  {
    if ( (Null->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Null);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Null);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::XML *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::XML,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::XML *)(dword_AAD0E4 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD04C + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,3,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,3,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD19C + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,35,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,35,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD36C + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,36,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,36,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD024 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,37,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,37,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD774 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,13,bool,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  bool v10; // zf
  Scaleform::GFx::AS3::Value *v11; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::Extra v13; // edx
  Scaleform::GFx::AS3::Value v14; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Value const &> args; // [esp+28h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v14 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v14.Flags;
  }
  def_ags._0.value.VNumber = v14.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v14.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v14);
    LOWORD(Flags) = v14.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
  }
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  if ( !argc )
    argv = &def_ags;
  v10 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v10 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, bool *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,13,bool,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD1B4 + v6.VInt),
      &args.r,
      &argv->_0);
    if ( !args.Vm->HandleException )
    {
      v11 = args.Result;
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v13.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v14.Bonus;
      LOBYTE(v14.Flags) = r;
      v11->value.VS._1.VInt = v14.Flags;
      v11->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v13.pWeakProxy;
    }
  }
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD2BC + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,38,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,38,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD144 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,39,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,39,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD724 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD294 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,12,bool,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  bool v10; // zf
  Scaleform::GFx::AS3::Value *v11; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::Extra v13; // edx
  Scaleform::GFx::AS3::Value v14; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Value const &> args; // [esp+28h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v14 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v14.Flags;
  }
  def_ags._0.value.VNumber = v14.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v14.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v14);
    LOWORD(Flags) = v14.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
  }
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  if ( !argc )
    argv = &def_ags;
  v10 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v10 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, bool *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,12,bool,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD1CC + v6.VInt),
      &args.r,
      &argv->_0);
    if ( !args.Vm->HandleException )
    {
      v11 = args.Result;
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v13.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v14.Bonus;
      LOBYTE(v14.Flags) = r;
      v11->value.VS._1.VInt = v14.Flags;
      v11->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v13.pWeakProxy;
    }
  }
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}
