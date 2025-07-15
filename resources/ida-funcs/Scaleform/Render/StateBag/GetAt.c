Scaleform::Render::StateBag *__thiscall Scaleform::Render::StateBag::GetAt(
        Scaleform::Render::StateBag *this,
        unsigned int index)
{
  Scaleform::Render::StateBag *result; // eax

  result = this;
  if ( ((int)this->pInterface & 1) == 0 )
    return (Scaleform::Render::StateBag *)(this->DataValue + 8 * index + 4);
  return result;
}
