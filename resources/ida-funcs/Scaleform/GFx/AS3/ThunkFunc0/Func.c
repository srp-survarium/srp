void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,3,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,3,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Array *)(dword_8F17FC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,7,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,7,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl::Array *)(dword_8F197C + obj->value.VS._1.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::Array *)(dword_8F198C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_8F26E4),
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
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_8F26BC),
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
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_8F2784),
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
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_8F25C4),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_8F256C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_8F26FC),
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
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_8F2654),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_8F260C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(v4.VInt + dword_8F25A4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_8F2734 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *)(dword_8F266C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)(dword_8F3054 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)(dword_8F2B34 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)(dword_8F30D4 + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,0,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)(dword_8F2A54 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *)(v4.VInt + dword_8F267C),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *)(dword_8F2564 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *)(v4.VInt + dword_8F269C),
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_utils::ByteArray *)(dword_8F0ACC + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,3,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_8F0A3C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_8F0A54 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_8F0A84 + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_8F0A74 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(v4.VInt + dword_8F0B3C),
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
    (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(v4.VInt + dword_8F0A4C),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_8F0AA4 + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,21,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_8F0A2C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_8F0B4C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_8F0A14 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_8F0B0C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_8F0B34 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)(dword_8F0AD4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F32A4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F31B4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F32BC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F3274 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F329C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F31CC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F326C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F3254 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F31C4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F3214 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F321C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F32AC + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(v4.VInt + dword_8F31A4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(v4.VInt + dword_8F32D4),
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
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(v4.VInt + dword_8F323C),
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
    (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(v4.VInt + dword_8F324C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F3184 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F32DC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F32E4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::Capabilities *)(dword_8F31E4 + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Class,1368,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Class,1368,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Class *)(dword_8F3598 + obj->value.VS._1.VInt),
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

  v4 = (Scaleform::GFx::AS3::Class *)(dword_8F35A0 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Class *)(dword_8F35A8 + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *)(dword_8F1264 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F18F4 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1BA4 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1CAC + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1934 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1C74 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1E14 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1EA4 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F18AC),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1DBC),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1C84),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1D74),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F191C),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1C14),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F195C),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F18EC),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1834),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1B84),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1DB4),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1ACC),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1BF4),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1A44),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1E6C),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1D2C),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1EF4),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1CB4),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F18B4),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F18E4),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F19DC),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F19F4),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1A2C),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1B2C),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1C6C),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1AA4),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1BBC),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1C64),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1C8C),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1CE4),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1EE4),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1CCC),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F188C),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1F34),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1CC4),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1B6C),
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
    (Scaleform::GFx::AS3::Instances::fl::Date *)(v4.VInt + dword_8F1DD4),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F308C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_8F2ECC + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F296C),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F30A4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F2D44),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F2DBC),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F294C),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F2A14),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F2F6C),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F2E0C),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F2D34),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_8F2D64 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F2EEC),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F2D4C),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F30AC),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F291C),
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
    (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(v4.VInt + dword_8F2EF4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
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
    (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v4.VInt + dword_8F262C),
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
    (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v4.VInt + dword_8F2554),
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
    (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v4.VInt + dword_8F2594),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_8F278C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v4.VInt + dword_8F255C),
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
    (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(v4.VInt + dword_8F26CC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
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
    (Scaleform::GFx::AS3::Instances::fl::Error *)(dword_8F1A34 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::Error *)(dword_8F17E4 + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::Error *)(dword_8F1EAC + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent,0,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *)(dword_8F2284 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_8F23E4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_8F1FD4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_8F1FCC + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_8F23A4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_8F20DC + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)(dword_8F20A4 + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(dword_8F334C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(dword_8F342C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(dword_8F338C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(dword_8F3424 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *)(dword_8F2824 + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent,2,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)(dword_8F1FEC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)(dword_8F201C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(dword_8F33B4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(dword_8F33BC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(dword_8F34E4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_text::Font *)(dword_8F165C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,2,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::Font *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,2,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::Font *)(dword_8F1474 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,0,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::Font *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,0,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::Font *)(dword_8F14C4 + obj->value.VS._1.VInt),
    result);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *)(dword_8F309C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::FunctionBase *)(dword_8F1B44 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *)(dword_8F34B4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(dword_8F3524 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(v4.VInt + dword_8F332C),
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
    (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(v4.VInt + dword_8F335C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)(dword_8F3514 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_8F2104 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_8F202C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_8F2224 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v4.VInt + dword_8F2134),
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
    (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v4.VInt + dword_8F251C),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_8F208C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v4.VInt + dword_8F21C4),
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
    (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(v4.VInt + dword_8F241C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)(dword_8F21BC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(dword_8F1F8C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(v4.VInt + dword_8F26B4),
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
    (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(v4.VInt + dword_8F2724),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_8F261C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_8F25D4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_8F26AC + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(v4.VInt + dword_8F25BC),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(dword_8F26A4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *)(v4.VInt + dword_8F2544),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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
    (Scaleform::GFx::AS3::Classes::fl_system::IME *)(dword_8F31F4 + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::IME *)(dword_8F32B4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Classes::fl_system::IME *)(dword_8F3234 + obj->value.VS._1.VInt),
    result);
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
    (Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx *)(dword_8F34F4 + v4.VInt),
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
    (Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx *)(dword_8F3414 + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)(dword_8F2A44 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *)(dword_8F27C4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *)(dword_8F279C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *)(dword_8F27FC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_8F22EC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_8F2124 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_8F24FC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_8F1FE4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_8F1F94 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_8F2354 + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent,12,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_8F20C4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)(dword_8F216C + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,3,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_8F2D9C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_8F30B4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_8F2E2C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(v4.VInt + dword_8F2A4C),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_8F30E4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_8F28DC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_8F302C + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,22,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_8F2C14 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_8F313C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)(dword_8F2ABC + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Classes::fl::Math *)(v4.VInt + dword_8F1B3C),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)(v4.VInt + dword_8F11AC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)(dword_8F1164 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)(dword_8F10EC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,6,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,6,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)(dword_8F104C + obj->value.VS._1.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)(dword_8F119C + v4.VInt),
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
    (Scaleform::GFx::AS3::Classes::fl_ui::Mouse *)(dword_8F280C + v4.VInt),
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
    (Scaleform::GFx::AS3::Classes::fl_ui::Mouse *)(dword_8F27BC + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,3,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_ui::Mouse *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,3,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_ui::Mouse *)(dword_8F27EC + obj->value.VS._1.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_8F20E4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_8F2044 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_8F240C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_8F242C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_8F22FC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_8F2114 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_8F2504 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v4.VInt + dword_8F1FA4),
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
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v4.VInt + dword_8F2374),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(dword_8F23C4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v4.VInt + dword_8F24DC),
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
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)(v4.VInt + dword_8F1FFC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_8F2F9C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_8F2FFC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_8F2A94 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_8F310C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)(dword_8F2F34 + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Multitouch,2,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *)(dword_8F2794 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *)(dword_8F27A4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *)(dword_8F27E4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *)(dword_8F27DC + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_8F0CBC + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,5,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_net::NetConnection *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_8F0BB4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)(dword_8F0C4C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(dword_8F0F0C + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(v4.VInt + dword_8F120C),
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
    (Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *)(v4.VInt + dword_8F2164),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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
    (Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *)(v4.VInt + dword_8F24F4),
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
    (Scaleform::GFx::AS3::Instances::fl::QName *)(dword_8F1D34 + obj->value.VS._1.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::QName *)(dword_8F1C34 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::QName *)(dword_8F1B0C + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(v4.VInt + dword_8F1074),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(v4.VInt + dword_8F0FAC),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(v4.VInt + dword_8F0F34),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(v4.VInt + dword_8F0EA4),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(dword_8F0FB4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_8F1D24 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_8F1AFC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_8F1A6C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_8F1C44 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_8F1D9C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_8F1EBC + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_8F1D64 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl_display::Scene *)(dword_8F2FAC + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Scene *)(dword_8F2964 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_8F0BDC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_8F0D7C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *)(dword_8F2854 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *)(dword_8F2B9C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *)(dword_8F2A84 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0CCC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0CF4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0CEC + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0D74 + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0CAC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0E04 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0D84 + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0D6C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0C84 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0C7C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0CC4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(v4.VInt + dword_8F0CDC),
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
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(v4.VInt + dword_8F0D4C),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0B8C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0E7C + obj->value.VS._1.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0DEC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0CA4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0CFC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0B6C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0B7C + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0BBC + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0BF4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,15,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::Socket,15,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0C1C + obj->value.VS._1.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(dword_8F12AC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(dword_8F131C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(v4.VInt + dword_8F129C),
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
    (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(dword_8F12D4 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(dword_8F12A4 + obj->value.VS._1.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(dword_8F1304 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *)(v4.VInt + dword_8F12F4),
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
    (Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *)(v4.VInt + dword_8F12E4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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
    (Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *)(v4.VInt + dword_8F12FC),
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
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_8F1344),
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
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_8F1314),
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
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_8F134C),
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
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_8F12DC),
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
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_8F1324),
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
    (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)(v4.VInt + dword_8F132C),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)(dword_8F2E8C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)(dword_8F2FDC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_display::Stage *)(dword_8F300C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F2FF4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F299C + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F2BC4 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(v4.VInt + dword_8F3024),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F305C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F2E1C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F2874 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F307C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F2B64 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F2E7C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F2A9C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F2D14 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(v4.VInt + dword_8F2B3C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F2B14 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(dword_8F3114 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_display::Stage *)(v4.VInt + dword_8F2CB4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_system::System *)(dword_8F3174 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Classes::fl_system::System *)(dword_8F3284 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,4,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::System *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,4,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::System *)(dword_8F327C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,5,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::System *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,5,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::System *)(dword_8F3244 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,0,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::System *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,0,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Classes::fl_system::System *)(dword_8F31AC + obj->value.VS._1.VInt),
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

  v4 = (Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *)(dword_8F3404 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *)(dword_8F34EC + v4.VInt),
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
    (Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *)(dword_8F32F4 + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F1454 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F1634 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F1604 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F1494 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F1714 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F170C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F1624 + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,29,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F16C4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F1444 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F13BC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F150C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F15F4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F146C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F147C + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextField,41,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F17AC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F14A4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F1694 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F141C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F178C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v4.VInt + dword_8F1684),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F135C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v4.VInt + dword_8F168C),
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
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v4.VInt + dword_8F15DC),
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
    (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v4.VInt + dword_8F1384),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F167C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F14BC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F1734 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F1424 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_8F17B4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_8F142C + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,4,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,4,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_8F1704 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,6,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,6,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_8F1784 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,8,Scaleform::GFx::AS3::Value>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::TextFormat,8,Scaleform::GFx::AS3::Value>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)(dword_8F172C + obj->value.VS._1.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *)(dword_8F1374 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(v4.VInt + dword_8F0B24),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_8F09D4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_8F0AC4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_8F09E4 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,7,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,7,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_8F0B14 + obj->value.VS._1.VInt),
    result);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,8,Scaleform::GFx::AS3::Value const>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,8,Scaleform::GFx::AS3::Value const>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_8F09FC + obj->value.VS._1.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)(dword_8F0ADC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_8F2434 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_8F212C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_8F2444 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_8F2204 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_8F231C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_8F2464 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_8F2414),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_8F23D4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_8F2494),
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
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_8F2094),
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
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_8F21AC),
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
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_8F21A4),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(dword_8F2184 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_8F2274),
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
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_8F23EC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_8F0E8C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_8F0D24 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_8F0E4C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_8F0BD4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)(dword_8F0C24 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_8F107C),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_8F1234),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_8F103C),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_8F0F24),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_8F10C4),
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_8F10B4),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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
    (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v4.VInt + dword_8F0FFC),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(dword_8F3764 + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(dword_8F38B4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(v4.VInt + dword_8F3664),
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
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(v4.VInt + dword_8F36C4),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_8F384C + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_8F37F4 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_8F393C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_8F3794 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)(dword_8F3614 + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)(dword_8F363C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_8F362C + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_8F375C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(dword_8F38CC + obj->value.VS._1.VInt);
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


void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(dword_8F35CC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(dword_8F36DC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)(dword_8F371C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F1BDC + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F1F74 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F1E4C + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F1E84 + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F1EB4 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F1F4C + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F1DA4 + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F1A64 + obj->value.VS._1.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F18BC + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_8F184C + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_8F1C54 + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_8F1AEC + obj->value.VS._1.VInt);
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_8F1CFC + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_8F1D7C + obj->value.VS._1.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_8F1A94 + v4.VInt),
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

  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_8F1E94 + obj->value.VS._1.VInt);
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
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_8F1DFC + v4.VInt),
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
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_8F1E7C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
