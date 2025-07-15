// attributes: thunk
void *boost::asio::asio_handler_allocate(unsigned int size, ...)
{
  return operator new(size);
}
