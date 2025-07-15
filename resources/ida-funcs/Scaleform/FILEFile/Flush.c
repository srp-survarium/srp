BOOL __usercall Scaleform::FILEFile::Flush@<eax>(Scaleform::FILEFile *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  return fflush(a2, a3, this->fs) == 0;
}
