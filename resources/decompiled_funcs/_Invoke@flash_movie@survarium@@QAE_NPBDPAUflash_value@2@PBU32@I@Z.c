int __userpurge survarium::flash_movie::Invoke@<eax>(
        const Scaleform::GFx::Value *pargs@<ecx>,
        unsigned int numArgs@<eax>,
        survarium::flash_movie *this,
        const char *ppathToMethod,
        Scaleform::GFx::Value *presult)
{
  return Scaleform::GFx::Movie::Invoke(this->m_movie, ppathToMethod, presult, pargs, numArgs);
}
