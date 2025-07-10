Scaleform::Ptr<Scaleform::GFx::LogState> *__thiscall Scaleform::GFx::StateBag::GetLogState(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::LogState> *result)
{
  result->pObject = (Scaleform::GFx::LogState *)this->GetStateAddRef(this, 2);
  return result;
}
