survarium::simple_game_project *__userpurge survarium::simple_game_project::`scalar deleting destructor'@<eax>(
        survarium::simple_game_project *this@<ecx>,
        const char *edi0@<edi>,
        char a2)
{
  survarium::simple_game_project::~simple_game_project(this, edi0);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
