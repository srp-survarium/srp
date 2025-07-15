void __userpurge survarium::flash_movie::SetVariable(const char *value@<eax>, survarium::flash_movie *this, char *name)
{
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::GFx::Value v4; // [esp+0h] [ebp-18h] BYREF

  v4.pObjectInterface = 0;
  v4.mValue.IValue = (int)value;
  m_movie = this->m_movie;
  v4.Type = VT_String;
  Scaleform::GFx::Movie::SetVariable(m_movie, name, &v4, SV_Sticky);
  Scaleform::GFx::Value::~Value(&v4);
}
