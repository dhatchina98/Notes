# Mutex and Semaphore

- Mutex and Semaphore are synchronise primitives and both are help to synchronise the resources 

## Mutex (Mutual Exclusion)

- it allows only `one thread`.
- only two states : `locked / unlocked`.
- it's a `locking mechanism`.(ex:producer acquire the lock and produce data then release the lock then consumer acquire the lock then consume data)
- `one common resource` and `multiple threads` are racing to access that resource and one thread get chance to access the resource at a time.


# Semaphore

- it allows `multiple threads` based on their initialization.
- `count` based limitation.
- it's a `signalling mechanism`.(ex: producer produced the data and send signal to consumer to consume and consumer after consumtion give signal to producer. there is no locking machanism)
- multiple resources and multiple threads but only count no of threads allowed to access the resources.