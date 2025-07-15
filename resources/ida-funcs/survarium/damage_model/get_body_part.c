survarium::body_part_parameters *__userpurge survarium::damage_model::get_body_part@<eax>(
        survarium::damage_model *this@<ecx>,
        int a2@<eax>,
        char *part_name)
{
  int **i; // esi

  for ( i = *(int ***)(a2 + 272); ; i = (int **)*i )
  {
    if ( !i )
      return 0;
    if ( !vostok::strings::compare((const char *)i[29], part_name) )
      break;
  }
  return (survarium::body_part_parameters *)i;
}
