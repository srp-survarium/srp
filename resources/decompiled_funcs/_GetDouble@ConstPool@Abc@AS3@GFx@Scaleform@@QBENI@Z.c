double __thiscall Scaleform::GFx::AS3::Abc::ConstPool::GetDouble(
        Scaleform::GFx::AS3::Abc::ConstPool *this,
        const unsigned __int8 *ind)
{
  if ( !ind )
    return 0.0;
  ind = &this->Doubles[8 * (_DWORD)ind - 8];
  return Scaleform::GFx::AS3::Abc::ReadDouble<unsigned char>(&ind);
}
