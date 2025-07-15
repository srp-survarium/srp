void __userpurge survarium::flash_movie::SetVariable(
        const char *name@<edx>,
        const char *value@<eax>,
        survarium::flash_movie *this)
{
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::GFx::Value v4; // [esp+0h] [ebp-18h] BYREF

  v4.mValue.IValue = (int)value;
  m_movie = this->m_movie;
  v4.pObjectInterface = 0;
  v4.Type = VT_String;
  Scaleform::GFx::Movie::SetVariable(m_movie, name, &v4, SV_Sticky);
  if ( (v4.Type & 0x40) != 0 )
    v4.pObjectInterface->ObjectRelease(v4.pObjectInterface, &v4, (void *)v4.mValue.IValue);
}


void __userpurge survarium::flash_movie::SetVariable(
        const char *name@<ecx>,
        const Scaleform::GFx::Value *value@<eax>,
        survarium::flash_movie *this)
{
  Scaleform::GFx::Movie::SetVariable(this->m_movie, name, value, SV_Sticky);
}
