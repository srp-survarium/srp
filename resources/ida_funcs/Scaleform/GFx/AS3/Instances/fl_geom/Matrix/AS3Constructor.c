void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  long double *p_a; // eax
  long double *p_b; // edi
  long double *p_c; // ebx
  long double *p_d; // ebp
  long double *p_tx; // edx
  long double *p_ty; // ecx
  bool v9; // zf
  Scaleform::GFx::AS3::Value *v10; // esi
  unsigned int v11; // edi
  long double *result; // [esp+Ch] [ebp-8h]
  long double *v13; // [esp+10h] [ebp-4h]

  this->a = 1.0;
  p_a = &this->a;
  this->b = 0.0;
  p_b = &this->b;
  this->c = 0.0;
  p_c = &this->c;
  p_d = &this->d;
  this->d = 1.0;
  p_tx = &this->tx;
  p_ty = &this->ty;
  v9 = argc == 0;
  *p_tx = 0.0;
  result = p_tx;
  *p_ty = 0.0;
  v13 = p_ty;
  if ( !v9 )
  {
    v10 = argv;
    if ( Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argv, p_a)->Result
      && argc > 1
      && Scaleform::GFx::AS3::Value::Convert2Number(v10 + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, p_b)->Result )
    {
      v11 = argc;
      if ( argc > 2
        && Scaleform::GFx::AS3::Value::Convert2Number(v10 + 2, (Scaleform::GFx::AS3::CheckResult *)&argc, p_c)->Result
        && v11 > 3
        && Scaleform::GFx::AS3::Value::Convert2Number(v10 + 3, (Scaleform::GFx::AS3::CheckResult *)&argc, p_d)->Result
        && v11 > 4
        && Scaleform::GFx::AS3::Value::Convert2Number(v10 + 4, (Scaleform::GFx::AS3::CheckResult *)&argc, result)->Result
        && v11 > 5 )
      {
        Scaleform::GFx::AS3::Value::Convert2Number(v10 + 5, (Scaleform::GFx::AS3::CheckResult *)&argc, v13);
      }
    }
  }
}
