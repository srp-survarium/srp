Scaleform::GFx::ASMovieRootBase_vtbl *__thiscall Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(
        Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  this->pDispObj->pASRoot->CheckAvm(this->pDispObj->pASRoot);
  return this->pDispObj->pASRoot[2].__vftable;
}
