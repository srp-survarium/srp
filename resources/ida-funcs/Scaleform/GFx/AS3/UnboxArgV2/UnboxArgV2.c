void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,long>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,long,long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<long,long> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<long,long> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->r = result;
  this->Vm = v9;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,unsigned long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,unsigned long>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,long,unsigned long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<long,unsigned long> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<long,unsigned long> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->r = result;
  this->Vm = v9;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,bool>::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,bool>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,long,bool> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<long,bool> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<long,bool> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->r = result;
  this->Vm = v9;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    this->a1 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,unsigned long,double>::UnboxArgV2<Scaleform::GFx::AS3::Value const,unsigned long,double>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,unsigned long,double> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<unsigned long,double> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<unsigned long,double> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->r = result;
  this->Vm = v9;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,double,double>::UnboxArgV2<Scaleform::GFx::AS3::Value const,double,double>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,double,double> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<double,double> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<double,double> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->r = result;
  this->Vm = v9;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,bool,unsigned long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,bool,unsigned long>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,bool,unsigned long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<bool,unsigned long> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<bool,unsigned long> *v6; // ebx

  v6 = da;
  this->Vm = vm;
  this->r = result;
  this->a0 = v6->_0;
  if ( argc )
    this->a0 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  this->a1 = v6->_1;
  if ( !vm->HandleException && argc > 1 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<long,Scaleform::GFx::ASString const &,long>::UnboxArgV2<long,Scaleform::GFx::ASString const &,long>(
        Scaleform::GFx::AS3::UnboxArgV2<long,Scaleform::GFx::ASString const &,long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,long> *da)
{
  Scaleform::GFx::AS3::Value *v6; // ebx
  const Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,long> *v8; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_a0; // edi
  Scaleform::GFx::ASStringManager *pManager; // ebx
  Scaleform::GFx::ASStringNode *v12; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // ebx

  v6 = argv;
  v8 = da;
  this->Vm = vm;
  this->Result = result;
  this->r = 0;
  pNode = v8->_0.pNode;
  p_a0 = &this->a0;
  this->a0.pNode = v8->_0.pNode;
  ++pNode->RefCount;
  if ( argc )
  {
    if ( (v6->Flags & 0x1F) - 12 > 3 || v6->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(v6, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a0);
    }
    else
    {
      pManager = p_a0->pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      v12 = p_a0->pNode;
      p_NullStringNode = &pManager->NullStringNode;
      if ( p_a0->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      p_a0->pNode = p_NullStringNode;
      v6 = argv;
    }
  }
  this->a1 = da->_1;
  if ( !vm->HandleException && argc > 1 )
    Scaleform::GFx::AS3::Value::Convert2Int32(
      v6 + 1,
      (Scaleform::GFx::AS3::CheckResult *)&argv,
      (Scaleform::GFx::AS3::Value::V1U *)&this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<long,long,Scaleform::GFx::ASString const &>::UnboxArgV2<long,long,Scaleform::GFx::ASString const &>(
        Scaleform::GFx::AS3::UnboxArgV2<long,long,Scaleform::GFx::ASString const &> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<long,Scaleform::GFx::ASString const &> *da)
{
  bool v6; // zf
  Scaleform::GFx::AS3::VM *v7; // ebx
  const Scaleform::GFx::AS3::DefArgs2<long,Scaleform::GFx::ASString const &> *v8; // ebp
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_a1; // edi
  Scaleform::GFx::ASStringManager *pManager; // ebx
  Scaleform::GFx::ASStringNode *v13; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // ebx

  v6 = argc == 0;
  v7 = vm;
  v8 = da;
  this->Result = result;
  this->Vm = v7;
  this->r = 0;
  this->a0 = v8->_0;
  if ( !v6 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  pNode = v8->_1.pNode;
  p_a1 = &this->a1;
  this->a1.pNode = pNode;
  ++pNode->RefCount;
  if ( !v7->HandleException && argc > 1 )
  {
    if ( (argv[1].Flags & 0x1F) - 12 > 3 || argv[1].value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->a1);
    }
    else
    {
      pManager = p_a1->pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      v13 = p_a1->pNode;
      p_NullStringNode = &pManager->NullStringNode;
      v6 = p_a1->pNode->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      p_a1->pNode = p_NullStringNode;
    }
  }
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<long,unsigned long,long>::UnboxArgV2<long,unsigned long,long>(
        Scaleform::GFx::AS3::UnboxArgV2<long,unsigned long,long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<unsigned long,long> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<unsigned long,long> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->Result = result;
  this->Vm = v9;
  this->r = 0;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(
      argv,
      (Scaleform::GFx::AS3::CheckResult *)&vm,
      (Scaleform::GFx::AS3::Value::V1U *)&this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Int32(
      argv + 1,
      (Scaleform::GFx::AS3::CheckResult *)&argv,
      (Scaleform::GFx::AS3::Value::V1U *)&this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<long,double,long>::UnboxArgV2<long,double,long>(
        Scaleform::GFx::AS3::UnboxArgV2<long,double,long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<double,long> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<double,long> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->Result = result;
  this->Vm = v9;
  this->r = 0;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Int32(
      argv + 1,
      (Scaleform::GFx::AS3::CheckResult *)&argv,
      (Scaleform::GFx::AS3::Value::V1U *)&this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<long,double,double>::UnboxArgV2<long,double,double>(
        Scaleform::GFx::AS3::UnboxArgV2<long,double,double> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<double,double> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<double,double> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->Result = result;
  this->Vm = v9;
  this->r = 0;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<double,double,double>::UnboxArgV2<double,double,double>(
        Scaleform::GFx::AS3::UnboxArgV2<double,double,double> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<double,double> *da)
{
  Scaleform::GFx::AS3::Value *v6; // eax
  Scaleform::GFx::AS3::VM *v7; // edi
  const Scaleform::GFx::AS3::DefArgs2<double,double> *v9; // ebx
  unsigned int v10; // ebp

  v6 = result;
  v7 = vm;
  this->Vm = vm;
  this->Result = v6;
  this->r = Scaleform::GFx::NumberUtil::NaN();
  v9 = da;
  v10 = argc;
  this->a0 = da->_0;
  if ( v10 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v9->_1;
  if ( !v7->HandleException && v10 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::ASString,long,long>::UnboxArgV2<Scaleform::GFx::ASString,long,long>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::ASString,long,long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<long,long> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<long,long> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax

  v6 = da;
  v7 = argc;
  this->Result = result;
  v9 = vm;
  this->Vm = vm;
  p_EmptyStringNode = &v9->StringManagerRef->pStringManager->EmptyStringNode;
  this->r.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::ASString,unsigned long,Scaleform::GFx::ASString const &>::UnboxArgV2<Scaleform::GFx::ASString,unsigned long,Scaleform::GFx::ASString const &>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::ASString,unsigned long,Scaleform::GFx::ASString const &> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<unsigned long,Scaleform::GFx::ASString const &> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<unsigned long,Scaleform::GFx::ASString const &> *v6; // ebp
  Scaleform::GFx::AS3::VM *v8; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  bool v10; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_a1; // ebx
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *v14; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi

  v6 = da;
  this->Result = result;
  v8 = vm;
  this->Vm = vm;
  p_EmptyStringNode = &v8->StringManagerRef->pStringManager->EmptyStringNode;
  this->r.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v10 = argc == 0;
  this->a0 = v6->_0;
  if ( !v10 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  pNode = v6->_1.pNode;
  p_a1 = &this->a1;
  this->a1.pNode = pNode;
  ++pNode->RefCount;
  if ( !v8->HandleException && argc > 1 )
  {
    if ( (argv[1].Flags & 0x1F) - 12 > 3 || argv[1].value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->a1);
    }
    else
    {
      pManager = p_a1->pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      v14 = p_a1->pNode;
      p_NullStringNode = &pManager->NullStringNode;
      v10 = p_a1->pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      p_a1->pNode = p_NullStringNode;
    }
  }
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value,double,long>::UnboxArgV2<Scaleform::GFx::AS3::Value,double,long>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value,double,long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<double,long> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<double,long> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->r = result;
  this->Vm = v9;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,long,long>::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,long,long>(
        Scaleform::GFx::AS3::UnboxArgV2<long,long,long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<long,long> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<long,long> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->Result = result;
  this->Vm = v9;
  this->r = 0;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<bool,long,long>::UnboxArgV2<bool,long,long>(
        Scaleform::GFx::AS3::UnboxArgV2<bool,long,long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<long,long> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<long,long> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->Result = result;
  this->Vm = v9;
  this->r = 0;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<bool,unsigned long,unsigned long>::UnboxArgV2<bool,unsigned long,unsigned long>(
        Scaleform::GFx::AS3::UnboxArgV2<bool,unsigned long,unsigned long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<unsigned long,unsigned long> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<unsigned long,unsigned long> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->Result = result;
  this->Vm = v9;
  this->r = 0;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV2<bool,double,double>::UnboxArgV2<bool,double,double>(
        Scaleform::GFx::AS3::UnboxArgV2<bool,double,double> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<double,double> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<double,double> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->Result = result;
  this->Vm = v9;
  this->r = 0;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}
