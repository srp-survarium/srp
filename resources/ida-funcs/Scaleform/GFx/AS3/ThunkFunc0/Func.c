void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent,2,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent,2,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *)(dword_AADD74 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,3,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,3,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Array *)(dword_AAD044 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,7,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,7,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Array *)(dword_AAD1C4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::Array *)(dword_AAD1D4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Array *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,2,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,2,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_AADF2C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,4,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,4,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_AADF04),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,6,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,6,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_AADFCC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,8,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,8,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_AADE0C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,10,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADDB4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,10,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_AADF44),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,16,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,16,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_AADE9C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,18,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADE54 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,18,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,20,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,20,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_AADDEC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,22,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,22,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADF74 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,12,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADF7C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,12,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,14,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_AADEB4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter,14,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,2,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,2,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)(dword_AAE66C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,4,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)(dword_AAE89C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,4,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)(dword_AAE37C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,3,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)(dword_AAE91C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,3,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,10,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,10,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)(dword_AAE504 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,0,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)(dword_AAE29C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,0,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,22,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,22,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)(dword_AAE78C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,2,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,2,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *)(v4.VInt + dword_AADEC4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,4,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *)(dword_AADDAC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,4,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *)(v4.VInt + dword_AADEE4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_utils::ByteArray,1,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_utils::ByteArray *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_utils::ByteArray *)(dword_AAC314 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_utils::ByteArray *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_utils::ByteArray,1,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,1,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,1,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC2E4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,3,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC284 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,3,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,5,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC29C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,5,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,7,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC2CC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,7,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,9,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,9,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC254 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC2BC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,16,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,16,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(v4.VInt + dword_AAC384),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,17,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,17,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(v4.VInt + dword_AAC294),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,18,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC2EC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,18,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,20,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,20,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC334 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,21,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC274 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,21,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,22,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC394 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,22,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,23,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC25C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,23,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,24,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC354 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,24,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,25,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,25,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC2AC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,27,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,27,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC24C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,13,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC37C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,13,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,14,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_AAC31C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,14,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,1,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEAEC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,1,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAE9FC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,3,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEB04 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,3,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,4,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEABC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,4,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,5,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEAE4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,5,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,6,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEA14 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,6,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,7,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEAB4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,7,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,8,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEA9C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,8,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,9,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEA0C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,9,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,10,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEA5C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,10,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEA64 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,16,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEAF4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,16,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,17,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,17,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEA74 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,18,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,18,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEADC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,19,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,19,double>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(v4.VInt + dword_AAE9EC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,20,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,20,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAE9B4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,21,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,21,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAE9E4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,22,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,22,double>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(v4.VInt + dword_AAEB1C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,23,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,23,double>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(v4.VInt + dword_AAEA84),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,24,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,24,double>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(v4.VInt + dword_AAEA94),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,25,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,25,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAE9D4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,26,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,26,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEA4C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,11,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAE9CC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,11,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,12,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEB24 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,12,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,13,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEB2C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,13,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,14,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::Capabilities *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEA2C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,14,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,15,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,15,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_AAEAA4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Class,1368,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Class,1368,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Class *)(dword_AAEDE0 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Class,1369,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Class *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Class *)(dword_AAEDE8 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Class *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Class,1369,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Class,1370,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Class,1370,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Class *)(dword_AAEDF0 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *)(dword_AAC7E4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *)(dword_AACAAC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu,5,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu,5,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *)(dword_AADFFC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,2,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,2,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD13C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD3EC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD4F4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,5,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,5,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD17C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,6,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,6,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD4BC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,7,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,7,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD65C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,8,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,8,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_AAD6EC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,9,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,9,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD0F4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,10,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,10,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD604),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD4CC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,16,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,16,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD5BC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,17,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,17,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD164),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,18,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,18,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD45C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,19,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,19,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD1A4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,20,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,20,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD134),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,21,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,21,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD07C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,22,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,22,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD3CC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,23,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,23,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD5FC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,24,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,24,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD314),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,25,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,25,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD43C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,26,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,26,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD28C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,41,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,41,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD6B4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,43,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,43,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD574),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,45,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,45,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD73C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,47,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,47,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD4FC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,49,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,49,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD0FC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,51,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,51,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD12C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,53,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,53,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD224),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,55,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,55,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD23C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,57,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,57,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD274),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,59,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,59,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD374),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,61,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,61,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD4B4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,63,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,63,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD2EC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,65,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,65,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD404),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,67,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,67,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD4AC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,69,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,69,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD4D4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,71,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,71,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD52C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,72,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,72,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD72C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,73,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,73,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD514),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,11,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,11,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD0D4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,12,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,12,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD77C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,13,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,13,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD50C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,14,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,14,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD3B4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,15,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Date,15,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_AAD61C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,2,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,2,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE8D4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE8DC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,6,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE714 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,6,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,10,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,10,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE1B4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,16,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,16,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE8EC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,17,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,17,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE34C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,23,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,23,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE58C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,25,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,25,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE604),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,27,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,27,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE194),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,29,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,29,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE25C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,33,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,33,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE7B4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,35,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,35,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE654),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,37,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,37,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE57C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,44,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE5AC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,44,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,46,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,46,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE734),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,48,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,48,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE594),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,50,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,50,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE8F4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,52,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,52,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE164),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,15,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,15,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_AAE73C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,2,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *)(dword_AAE76C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,2,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,3,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *)(dword_AAE924 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,3,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *)(dword_AAE564 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,2,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,2,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v4.VInt + dword_AADE74),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,4,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,4,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v4.VInt + dword_AADD9C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,6,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,6,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v4.VInt + dword_AADDDC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,8,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADFD4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,8,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,10,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,10,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v4.VInt + dword_AADDA4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v4.VInt + dword_AADF14),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,16,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADF34 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,16,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,18,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADE94 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,18,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,20,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,20,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v4.VInt + dword_AADE7C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,12,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADECC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,12,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,14,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADF9C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,14,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Error,1,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Error *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Error,1,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Error *)(dword_AAD27C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Error,2,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Error *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Error,2,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Error *)(dword_AAD02C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Error,0,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::Error *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::Error *)(dword_AAD6F4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Error *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Error,0,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent,2,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent,2,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *)(dword_AADA14 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent,0,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *)(dword_AADACC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent,0,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,1,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_AADC2C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,1,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,3,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_AAD81C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,3,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,5,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,5,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_AAD814 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,8,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_AADBEC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,8,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,9,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,9,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_AADAD4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,10,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,10,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_AAD8FC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_AAD924 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,11,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,11,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_AAD86C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,12,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::Event,12,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_AAD8EC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,1,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(dword_AAEB94 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,1,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,3,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(dword_AAEC74 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,3,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,10,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(dword_AAEBD4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,10,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,12,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(dword_AAEC6C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,12,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,1,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *)(dword_AAE06C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,1,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *)(dword_AAE084 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *)(dword_AAE094 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,2,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)(dword_AAD834 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,2,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,6,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)(dword_AAD864 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,6,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,9,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,9,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)(dword_AAD854 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,0,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,0,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)(dword_AAD904 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,1,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(dword_AAEBFC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,1,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,3,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(dword_AAEC04 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,3,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,8,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(dword_AAED2C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,8,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,1,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::Font *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,1,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::Font *)(dword_AACEA4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,2,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::Font *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,2,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::Font *)(dword_AACCBC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,0,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::Font *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,0,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::Font *)(dword_AACD0C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::FrameLabel,1,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::FrameLabel,1,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *)(dword_AAE0F4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::FrameLabel,0,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *)(dword_AAE8E4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::FrameLabel,0,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::FunctionBase,565,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::FunctionBase *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::FunctionBase *)(dword_AAD38C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::FunctionBase *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::FunctionBase,565,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::GamePad,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *)(dword_AAECFC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::GamePad,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,2,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(dword_AAED6C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,2,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,4,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,4,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(v4.VInt + dword_AAEB74),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,6,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,6,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(v4.VInt + dword_AAEBA4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,9,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,9,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(dword_AAEC0C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(dword_AAED5C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_AAD94C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,4,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_AAD874 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,4,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,6,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_AADA6C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,6,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,8,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,8,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v4.VInt + dword_AAD97C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,10,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,10,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v4.VInt + dword_AADD64),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_AAD8D4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,16,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,16,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v4.VInt + dword_AADA0C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,17,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,17,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v4.VInt + dword_AADC64),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,19,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,19,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_AADAFC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,20,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,20,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_AADD34 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,12,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,12,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_AADC44 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,14,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_AADA04 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::GestureEvent,14,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,86,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(dword_AAD7D4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,86,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,2,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,2,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(v4.VInt + dword_AADEFC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,4,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,4,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(v4.VInt + dword_AADF6C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,6,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_AADE64 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,6,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,8,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_AADE1C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,8,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,10,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_AADEF4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,10,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(v4.VInt + dword_AADE04),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,12,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_AADEEC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,12,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,14,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,14,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(v4.VInt + dword_AADD8C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Graphics,3,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Graphics *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Graphics,3,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)(dword_AAE6EC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Graphics,10,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Graphics *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Graphics,10,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)(dword_AAE22C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::IME,1,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::IME *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::IME,1,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::IME *)(dword_AAEA3C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::IME,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::IME *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::IME *)(dword_AAEAFC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::IME *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::IME,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::IME,4,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::IME *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::IME,4,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::IME *)(dword_AAEA7C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::IMEEvent,1,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::IMEEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::IMEEvent,1,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::IMEEvent *)(dword_AADB04 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx *)(dword_AAED3C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx *)(dword_AAEC5C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(dword_AAE5D4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,4,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,4,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(dword_AAE354 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,6,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(dword_AAE0A4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,6,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,8,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(dword_AAE534 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,8,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,10,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(dword_AAE28C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,10,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *)(dword_AADB3C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent,0,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent,0,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *)(dword_AADA2C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Keyboard,1,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *)(dword_AAE00C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Keyboard,1,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Keyboard,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *)(dword_AADFE4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Keyboard,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Keyboard,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *)(dword_AAE044 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Keyboard,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,2,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AADB34 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,2,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,4,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AAD96C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,4,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,6,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AADD44 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,6,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,8,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AAD82C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,8,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,10,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AAD7DC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,10,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AADB9C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,17,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,17,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AADCE4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,18,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,18,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AADCBC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,12,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AAD90C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,12,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,14,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_AAD9B4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,14,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Loader,2,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Loader *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Loader,2,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Loader *)(dword_AAE644 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Loader,5,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Loader *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Loader,5,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Loader *)(dword_AAE484 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,3,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE5E4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,3,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,4,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE8FC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,4,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,5,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE674 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,5,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,9,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,9,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE4AC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,10,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,10,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(v4.VInt + dword_AAE294),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE92C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,18,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE124 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,18,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,20,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE874 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,20,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,21,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,21,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE404 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,22,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE45C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,22,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,11,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE984 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,11,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,13,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,13,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE8B4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,15,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_AAE304 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,15,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl::Math,17,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl::Math,17,double>::Method)(
    (Scaleform::GFx::AS3::Classes::fl::Math *)(v4.VInt + dword_AAD384),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)(v4.VInt + dword_AAC9F4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,24,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,24,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)(dword_AAC8D4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,12,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,12,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)(dword_AAC724 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,15,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)(dword_AAC9AC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,15,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,5,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,5,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)(dword_AAC934 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,6,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,6,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)(dword_AAC894 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,9,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,9,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)(dword_AAC9E4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,1,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Mouse *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,1,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_ui::Mouse *)(dword_AAE054 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,2,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Mouse *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,2,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_ui::Mouse *)(dword_AAE004 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,3,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Mouse *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,3,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_ui::Mouse *)(dword_AAE034 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AAD92C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,4,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AAD88C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,4,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,5,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AADC54 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,5,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,7,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AADC74 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,7,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,9,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AADB44 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,9,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AAD95C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,19,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AADD4C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,19,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,21,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,21,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v4.VInt + dword_AAD7EC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,22,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,22,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v4.VInt + dword_AADBBC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,24,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,24,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AAD944 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,25,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,25,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AADB1C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,11,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_AADC0C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,11,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,13,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,13,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v4.VInt + dword_AADD24),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,15,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent,15,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v4.VInt + dword_AAD844),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,1,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,1,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE0AC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,2,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,2,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE90C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,5,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE7E4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,5,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,7,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE844 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,7,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,9,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE2DC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,9,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,10,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE954 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,10,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,0,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE77C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,0,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,16,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,16,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE104 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,17,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,17,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE5C4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,18,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,18,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE54C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,19,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,19,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE5FC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,20,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,20,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE23C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,15,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,15,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_AAE4A4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,2,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *)(dword_AADFDC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,2,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,4,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *)(dword_AADFEC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,4,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,5,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *)(dword_AAE02C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,5,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,0,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,0,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *)(dword_AAE024 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::NetConnection *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_AAC504 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_AAC4DC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,5,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::NetConnection *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_AAC3FC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,5,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,7,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,7,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_AAC444 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,9,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,9,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_AAC63C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,10,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::NetConnection *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_AAC494 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,10,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,13,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,13,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_AAC48C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *)(dword_AADBE4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection,2,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection,2,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *)(v4.VInt + dword_AAC974),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection,4,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection,4,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *)(v4.VInt + dword_AAC97C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Point,7,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Point *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Point,7,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(dword_AAC754 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Point,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Point *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Point,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(v4.VInt + dword_AACA54),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,2,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,2,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *)(v4.VInt + dword_AADCC4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,4,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,4,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *)(v4.VInt + dword_AADC3C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,5,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,5,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *)(v4.VInt + dword_AADC9C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,7,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,7,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *)(dword_AAD934 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *)(v4.VInt + dword_AADA24),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,2,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,2,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *)(v4.VInt + dword_AAD9AC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,5,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,5,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *)(dword_AAD9FC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *)(v4.VInt + dword_AADD3C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,1,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::QName *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,1,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::QName *)(dword_AAD57C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::QName *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::QName *)(dword_AAD47C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,0,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::QName *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,0,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::QName *)(dword_AAD354 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,4,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,4,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(v4.VInt + dword_AAC8BC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,6,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,6,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(v4.VInt + dword_AAC7F4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,10,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,10,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(v4.VInt + dword_AAC77C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(v4.VInt + dword_AAC6EC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,23,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC7FC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,23,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,26,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,26,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AACAB4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,27,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,27,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_AAC7AC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,1,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::RegExp *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_AAD56C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,1,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::RegExp *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_AAD344 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,3,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::RegExp *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_AAD2B4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,3,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,4,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::RegExp *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_AAD48C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,4,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,6,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::RegExp *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_AAD5E4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,6,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,7,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::RegExp *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_AAD704 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,7,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,0,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::RegExp,0,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_AAD5AC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Scene,1,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Scene *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Scene,1,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Scene *)(dword_AAE7F4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Scene,2,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Scene *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Scene *)(dword_AAE1AC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Scene *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Scene,2,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,5,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_AAC424 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::SharedObject *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,5,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,7,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_AAC5C4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::SharedObject *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,7,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,8,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::SharedObject *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,8,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_AAC54C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,9,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::SharedObject *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,9,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_AAC47C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *)(dword_AAE09C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,10,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *)(dword_AAE3E4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,10,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,14,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *)(dword_AAE2CC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton,14,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,1,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC514 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,1,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC53C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC534 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,5,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,5,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC5BC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,6,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC4F4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,6,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,7,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC64C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,7,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,9,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,9,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC5CC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,10,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC5B4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,10,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC4CC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,16,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC4C4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,16,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,17,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC50C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,17,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,19,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,19,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(v4.VInt + dword_AAC524),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,20,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,20,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(v4.VInt + dword_AAC594),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,21,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC3D4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,21,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,23,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,23,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC6C4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,24,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC634 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,24,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,25,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC4EC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,25,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,26,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC544 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,26,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,27,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC3B4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,27,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,28,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,28,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC3C4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,11,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::Socket *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC404 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,11,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,13,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,13,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC43C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,15,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,15,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC464 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,1,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_media::Sound *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(dword_AACAF4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::Sound *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,1,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,3,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_media::Sound *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(dword_AACB64 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::Sound *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,3,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,4,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::Sound *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,4,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(v4.VInt + dword_AACAE4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,5,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::Sound *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,5,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(dword_AACB1C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,6,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::Sound *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,6,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(dword_AACAEC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_media::Sound *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(dword_AACB4C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::Sound *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,1,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,1,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *)(v4.VInt + dword_AACB3C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,2,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,2,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *)(v4.VInt + dword_AACB2C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,5,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,5,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *)(dword_AACB04 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *)(v4.VInt + dword_AACB44),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,2,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,2,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_AACB8C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,4,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,4,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_AACB5C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,6,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,6,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_AACB94),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,8,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,8,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_AACB24),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,10,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,10,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_AACB6C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_AACB74),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Sprite,8,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Sprite *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)(dword_AAE6D4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Sprite *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Sprite,8,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Sprite,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Sprite *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)(dword_AAE824 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Sprite *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Sprite,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Sprite,11,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Sprite *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Sprite,11,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)(dword_AAE6BC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_display::Stage,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_display::Stage *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_display::Stage *)(dword_AAE854 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_display::Stage *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_display::Stage,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE83C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE1E4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE40C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,8,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,8,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(v4.VInt + dword_AAE86C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,10,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE8A4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,10,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,0,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,0,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE274 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,16,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE664 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,16,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,19,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE0BC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,19,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,20,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,20,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE14C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,21,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,21,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE334 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,23,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,23,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE364 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,25,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE8C4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,25,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,27,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE3AC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,27,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,29,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE6C4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,29,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,31,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE2E4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,31,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,33,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE55C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,33,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,36,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,36,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(v4.VInt + dword_AAE384),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,44,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,44,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE3C4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,45,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE35C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,45,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,13,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Stage *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_AAE95C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,13,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,14,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Stage *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Stage,14,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(v4.VInt + dword_AAE4FC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent,1,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent,1,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *)(dword_AADADC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *)(dword_AADCD4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent,0,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent,0,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *)(dword_AAD894 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::StaticText,0,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::StaticText *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::StaticText,0,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::StaticText *)(dword_AACE94 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,1,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,1,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *)(dword_AACF3C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,1,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_system::System *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::System *)(dword_AAE9BC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::System *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,1,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,3,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::System *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,3,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::System *)(dword_AAEACC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,4,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::System *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,4,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::System *)(dword_AAEAC4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,5,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::System *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,5,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::System *)(dword_AAEA8C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,0,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::System *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,0,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::System *)(dword_AAE9F4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,1,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *)(dword_AAEC4C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,1,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *)(dword_AAED34 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *)(dword_AAEB3C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)(dword_AAD824 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,0,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,0,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)(dword_AADBC4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,2,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,2,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACDE4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACD4C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,6,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACC9C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,6,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,8,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACE7C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,8,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,10,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACE4C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,10,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACCDC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,16,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACF5C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,16,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,21,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACF54 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,21,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,23,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACE6C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,23,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,25,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,25,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACD44 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,27,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,27,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACBD4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,29,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACF0C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,29,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,30,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACC8C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,30,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,32,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACC04 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,32,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,33,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACD54 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,33,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,34,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACE3C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,34,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,36,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACCB4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,36,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,38,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACCC4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,38,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,39,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,39,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACE74 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,41,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACFF4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,41,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,43,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACCEC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,43,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,45,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACEDC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,45,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,47,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACC64 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,47,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,48,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACFD4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,48,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,49,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,49,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v4.VInt + dword_AACECC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,53,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,53,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACFDC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,55,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACBA4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,55,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,57,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,57,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v4.VInt + dword_AACED4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,58,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,58,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v4.VInt + dword_AACE24),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,59,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,59,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v4.VInt + dword_AACBCC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,61,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,61,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACF9C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,63,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACEC4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,63,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,65,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACD04 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,65,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,12,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACF7C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,12,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,14,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACC6C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,14,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,15,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACFFC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,15,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,2,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,2,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACC74 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,4,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,4,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACF4C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,6,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,6,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACFCC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,8,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,8,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACF74 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,10,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,10,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACC7C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,0,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,0,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACC34 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,16,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,16,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AAD004 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,18,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,18,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACD7C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,20,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,20,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACC5C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,22,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,22,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACC24 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,24,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,24,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACD34 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,26,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,26,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACE1C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,30,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,30,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACE14 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,32,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,32,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACFC4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,34,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,34,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACE8C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,12,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,12,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACE04 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,14,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,14,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_AACDC4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,0,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *)(dword_AACBBC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,0,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,1,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,1,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(v4.VInt + dword_AAC36C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,3,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_AAC21C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,3,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,5,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_AAC30C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,5,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,6,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,6,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_AAC22C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,7,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,7,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_AAC35C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,8,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,8,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_AAC244 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,0,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_AAC324 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,0,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TimerEvent,1,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TimerEvent,1,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *)(dword_AADB8C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TimerEvent,2,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TimerEvent,2,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *)(dword_AADAB4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADC7C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,4,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AAD974 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,4,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,6,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADC8C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,6,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,8,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADA4C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,8,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,10,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADB64 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,10,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADCAC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,16,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,16,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_AADC5C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,20,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADC1C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,20,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,22,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,22,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_AADCDC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,24,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,24,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_AAD8DC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,26,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,26,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_AAD9F4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,27,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,27,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_AAD9EC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,28,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AAD9CC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,28,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,31,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,31,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADC84 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,32,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,32,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_AADCB4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,12,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,12,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_AADABC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,14,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,14,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_AADC34),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,2,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,2,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)(v4.VInt + dword_AAD87C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,4,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,4,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)(v4.VInt + dword_AAD99C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,6,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,6,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)(v4.VInt + dword_AADD0C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,8,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,8,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)(v4.VInt + dword_AAD994),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)(v4.VInt + dword_AADBA4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,11,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent,11,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *)(dword_AADCEC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLLoader,1,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLLoader,1,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)(dword_AAC51C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,2,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC6D4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,2,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC5D4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,8,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,8,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC42C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,10,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC56C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,10,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,0,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC694 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,0,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,18,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,18,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC564 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,20,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC41C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,20,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,22,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,22,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC5DC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,12,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC46C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,12,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,14,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLRequest,14,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_AAC69C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLVariables,1,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLVariables,1,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::URLVariables *)(dword_AAC55C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,1,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,1,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_AAC8C4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,3,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,3,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_AACA7C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,5,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,5,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_AAC884),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,7,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,7,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_AAC76C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,9,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,9,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_AAC90C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,0,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,0,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_AAC8FC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,18,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,18,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AAC80C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,19,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,19,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_AAC844),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,20,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,20,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AAC764 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,23,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,23,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AACA4C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,3,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(dword_AAEFAC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,3,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(dword_AAF0A4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,5,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,5,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(dword_AAEFF4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(dword_AAF0FC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,17,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,17,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(v4.VInt + dword_AAEEAC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,15,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,15,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(v4.VInt + dword_AAEF0C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,3,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_AAF094 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,3,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_AAEF3C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,5,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,5,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_AAF104 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_AAF03C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,17,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_AAF184 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,17,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,15,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_AAEFDC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,15,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,3,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)(dword_AAEE5C + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,3,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)(dword_AAEE34 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,5,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,5,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)(dword_AAEF04 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)(dword_AAEE84 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,17,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,17,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)(dword_AAF164 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,15,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,15,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)(dword_AAF0EC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,3,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_AAEE74 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,3,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_AAEE2C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,5,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,5,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_AAF10C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_AAEFA4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,17,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,17,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_AAEE3C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,15,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,15,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_AAF11C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,3,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(dword_AAF114 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,3,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,4,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,4,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(dword_AAF0C4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,5,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,5,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(dword_AAF0B4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(dword_AAEE14 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,17,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(dword_AAEF24 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,17,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,15,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(dword_AAEF64 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,15,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,2,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,2,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD424 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,10,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD7BC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,10,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,17,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD694 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,17,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,18,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD6CC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,18,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,22,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD6FC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,22,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,23,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,23,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD794 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,27,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,27,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD5EC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,29,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,29,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD2AC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,39,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XML,39,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD104 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,2,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD094 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,2,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,3,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,3,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD49C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,16,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD334 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,16,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,17,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD544 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,17,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,20,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,20,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD5C4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,23,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,23,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD2DC + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,26,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD6DC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,26,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,30,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,30,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD644 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,32,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::XMLList,32,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD6C4 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
