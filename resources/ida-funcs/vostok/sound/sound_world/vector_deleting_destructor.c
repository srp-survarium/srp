vostok::sound::sound_world *__userpurge vostok::sound::sound_world::`vector deleting destructor'@<eax>(
        vostok::sound::sound_world *this@<ecx>,
        char *ebx0@<ebx>,
        char a2)
{
  vostok::sound::sound_world::~sound_world(this, ebx0);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
