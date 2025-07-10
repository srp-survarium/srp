Scaleform::GFx::StateBag *__thiscall Scaleform::GFx::Loader::GetStateBagImpl(Scaleform::GFx::MovieDefImpl *this)
{
  volatile int Value; // eax

  Value = this->RefCount.Value;
  if ( Value )
    return (Scaleform::GFx::StateBag *)(Value + 8);
  else
    return 0;
}
