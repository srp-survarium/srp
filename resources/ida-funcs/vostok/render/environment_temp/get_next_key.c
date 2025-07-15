vostok::render::cloud_key_parameters *__userpurge vostok::render::environment_temp::get_next_key@<eax>(
        vostok::render::environment_temp *this@<ecx>,
        vostok::render::cloud_key_parameters *a2@<eax>,
        vostok::render::environment_temp *result,
        unsigned int index)
{
  if ( (unsigned int)&this->keys + 1 < result->num_keys )
    qmemcpy(a2, &result->keys[(int)&this->keys + 1], sizeof(vostok::render::cloud_key_parameters));
  else
    qmemcpy(a2, result->keys, sizeof(vostok::render::cloud_key_parameters));
  return a2;
}
