void __userpurge vostok::render::clouds::set_key(
        vostok::render::clouds *this@<edx>,
        const unsigned int index@<eax>,
        const vostok::render::cloud_key_parameters *in_cloud_key_parameters)
{
  qmemcpy(&this->m_keys[index], in_cloud_key_parameters, sizeof(this->m_keys[index]));
}
