survarium::ladder *__userpurge survarium::ladder::`scalar deleting destructor'@<eax>(
        survarium::ladder *this@<ecx>,
        const char *ebp0@<ebp>,
        char a2)
{
  survarium::ladder::~ladder(this, ebp0);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
