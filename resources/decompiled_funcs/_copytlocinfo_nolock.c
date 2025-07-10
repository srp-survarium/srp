void __usercall copytlocinfo_nolock(threadlocaleinfostruct *ptlocid@<eax>, threadlocaleinfostruct *ptlocis@<ecx>)
{
  if ( ptlocis && ptlocid && ptlocid != ptlocis )
  {
    qmemcpy(ptlocid, ptlocis, sizeof(threadlocaleinfostruct));
    ptlocid->refcount = 0;
    __addlocaleref(ptlocid);
  }
}
