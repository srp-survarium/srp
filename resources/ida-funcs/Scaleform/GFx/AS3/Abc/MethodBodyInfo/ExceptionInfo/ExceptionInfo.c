void __thiscall Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo::ExceptionInfo(
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *this,
        unsigned int _from,
        unsigned int _to,
        unsigned int _target,
        unsigned int _exc_type_ind,
        unsigned int _var_name_ind)
{
  this->from = _from;
  this->to = _to;
  this->target = _target;
  this->exc_type_ind = _exc_type_ind;
  this->var_name_ind = _var_name_ind;
}


void __thiscall Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo::ExceptionInfo(
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *this)
{
  this->from = 0;
  this->to = 0;
  this->target = 0;
  this->exc_type_ind = 0;
  this->var_name_ind = 0;
}
