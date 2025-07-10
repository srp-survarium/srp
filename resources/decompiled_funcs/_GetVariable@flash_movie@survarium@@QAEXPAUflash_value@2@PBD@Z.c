void __userpurge survarium::flash_movie::GetVariable(
        Scaleform::GFx::Value *value@<ecx>,
        const char *name@<eax>,
        survarium::flash_movie *this)
{
  Scaleform::GFx::Movie::GetVariable(this->m_movie, value, name);
}
