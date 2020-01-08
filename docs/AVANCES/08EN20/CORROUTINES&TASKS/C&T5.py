#Tasks 

import asyncio

async def nested():
	return 42
	
async def main():
	#Schedule nested() to run soon concurrently
	#with "main()".
	task = asyncio.create_task(nested())
	
	#"Task" can now be used to cancel "nested()", or
	#can simply be awaited to wait until it is completed:
	await task

asyncio.run(main())
